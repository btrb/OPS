//
// auto-generated by ops.py
//
__constant__ int xdim0_multidim_kernel;
int xdim0_multidim_kernel_h = -1;
__constant__ int ydim0_multidim_kernel;
int ydim0_multidim_kernel_h = -1;
__constant__ int zdim0_multidim_kernel;
int zdim0_multidim_kernel_h = -1;


#undef OPS_ACC_MD0


#define OPS_ACC_MD0(d,x,y,z) ((x)+(xdim0_multidim_kernel*(y))+(xdim0_multidim_kernel*ydim0_multidim_kernel*(z))+(d)*xdim0_multidim_kernel*ydim0_multidim_kernel*zdim0_multidim_kernel)
//user function
__device__

void multidim_kernel_gpu(double *val, int *idx){
  val[OPS_ACC_MD0(0,0,0,0)] = (double)(idx[0]);
  val[OPS_ACC_MD0(1,0,0,0)] = (double)(idx[1]);
  val[OPS_ACC_MD0(2,0,0,0)] = (double)(idx[2]);
  printf("%d %d %d: %p %p %p\n",idx[0],idx[1],idx[2],&val[OPS_ACC_MD0(0,0,0,0)],&val[OPS_ACC_MD0(1,0,0,0)], &val[OPS_ACC_MD0(2,0,0,0)]);
}




#undef OPS_ACC_MD0

__global__ void ops_multidim_kernel(
double* __restrict arg0,
int arg_idx0, int arg_idx1, int arg_idx2,
int size0,
int size1,
int size2 ){


  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  int arg_idx[3];
  arg_idx[0] = arg_idx0+idx_x;
  arg_idx[1] = arg_idx1+idx_y;
  arg_idx[2] = arg_idx2+idx_z;
  arg0 += idx_x * 1+ idx_y * 1* xdim0_multidim_kernel + idx_z * 1 * xdim0_multidim_kernel * ydim0_multidim_kernel;

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    multidim_kernel_gpu(arg0, arg_idx);
  }

}

// host stub function
void ops_par_loop_multidim_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[2] = { arg0, arg1};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,2,range,0)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(0,"multidim_kernel");
    OPS_kernels[0].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<3; n++ ){
    start[n] = sb->decomp_disp[n];end[n] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (sb->id_m[n]==MPI_PROC_NULL && range[2*n] < 0) start[n] = range[2*n];
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n]==MPI_PROC_NULL && (range[2*n+1] > sb->decomp_disp[n]+sb->decomp_size[n]))
      end[n] += (range[2*n+1]-sb->decomp_disp[n]-sb->decomp_size[n]);
  }
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  int arg_idx[3];
  #ifdef OPS_MPI
  arg_idx[0] = sb->decomp_disp[0]+start[0];
  arg_idx[1] = sb->decomp_disp[1]+start[1];
  arg_idx[2] = sb->decomp_disp[2]+start[2];
  #else
  arg_idx[0] = start[0];
  arg_idx[1] = start[1];
  arg_idx[2] = start[2];
  #endif
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int zdim0 = args[0].dat->size[2];

  if (xdim0 != xdim0_multidim_kernel_h || ydim0 != ydim0_multidim_kernel_h || zdim0 != zdim0_multidim_kernel_h) {
    cudaMemcpyToSymbol( xdim0_multidim_kernel, &xdim0, sizeof(int) );
    xdim0_multidim_kernel_h = xdim0;
    cudaMemcpyToSymbol( ydim0_multidim_kernel, &ydim0, sizeof(int) );
    ydim0_multidim_kernel_h = ydim0;
    cudaMemcpyToSymbol( zdim0_multidim_kernel, &zdim0, sizeof(int) );
    zdim0_multidim_kernel_h = zdim0;
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, z_size);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);

  char *p_a[2];

  //set up initial pointers
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif
  int base0 = dat0 * 1 *
  (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - d_m[1]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    (start[2] * args[0].stencil->stride[2] - args[0].dat->base[2] - d_m[2]);
  p_a[0] = (char *)args[0].data_d + base0;


  ops_H_D_exchanges_device(args, 2);
  ops_halo_exchanges(args,2,range);

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[0].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  ops_multidim_kernel<<<grid, tblock >>> (  (double *)p_a[0], arg_idx[0], arg_idx[1], arg_idx[2],x_size, y_size, z_size);

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_kernels[0].time += t1-t2;
  }

  ops_set_dirtybit_device(args, 2);
  ops_set_halo_dirtybit3(&args[0],range);

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[0].mpi_time += t2-t1;
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
