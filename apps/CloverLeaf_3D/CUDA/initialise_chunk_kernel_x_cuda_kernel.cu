//
// auto-generated by ops.py on 2014-06-17 17:19
//

__constant__ int xdim0_initialise_chunk_kernel_x;
__constant__ int ydim0_initialise_chunk_kernel_x;
__constant__ int xdim1_initialise_chunk_kernel_x;
__constant__ int ydim1_initialise_chunk_kernel_x;
__constant__ int xdim2_initialise_chunk_kernel_x;
__constant__ int ydim2_initialise_chunk_kernel_x;

#define OPS_ACC0(x,y,z) (x+xdim0_initialise_chunk_kernel_x*(y)+xdim0_initialise_chunk_kernel_x*ydim0_initialise_chunk_kernel_x*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_initialise_chunk_kernel_x*(y)+xdim1_initialise_chunk_kernel_x*ydim1_initialise_chunk_kernel_x*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_initialise_chunk_kernel_x*(y)+xdim2_initialise_chunk_kernel_x*ydim2_initialise_chunk_kernel_x*(z))

//user function
__device__

void initialise_chunk_kernel_x(double *vertexx, const int *xx, double *vertexdx) {
  int x_min=field.x_min-2;
  int x_max=field.x_max-2;

  double min_x, d_x;
  d_x = (grid.xmax - grid.xmin)/(double)grid.x_cells;
  min_x=grid.xmin+d_x*field.left;

  vertexx[OPS_ACC0(0,0,0)] = min_x + d_x * (xx[OPS_ACC1(0,0,0)] - x_min);
  vertexdx[OPS_ACC2(0,0,0)] = (double)d_x;
}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2


__global__ void ops_initialise_chunk_kernel_x(
double* __restrict arg0,
const int* __restrict arg1,
double* __restrict arg2,
int size0,
int size1,
int size2 ){


  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 0 * xdim0_initialise_chunk_kernel_x + idx_z * 0 * xdim0_initialise_chunk_kernel_x * ydim0_initialise_chunk_kernel_x;
  arg1 += idx_x * 1 + idx_y * 0 * xdim1_initialise_chunk_kernel_x + idx_z * 0 * xdim1_initialise_chunk_kernel_x * ydim1_initialise_chunk_kernel_x;
  arg2 += idx_x * 1 + idx_y * 0 * xdim2_initialise_chunk_kernel_x + idx_z * 0 * xdim2_initialise_chunk_kernel_x * ydim2_initialise_chunk_kernel_x;

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    initialise_chunk_kernel_x(arg0, arg1, arg2);
  }

}

// host stub function
void ops_par_loop_initialise_chunk_kernel_x(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {

  ops_arg args[3] = { arg0, arg1, arg2};

  sub_block_list sb = OPS_sub_block_list[Block->index];
  //compute localy allocated range for the sub-block
  int start_add[3];
  int end_add[3];
  for ( int n=0; n<3; n++ ){
    start_add[n] = sb->istart[n];end_add[n] = sb->iend[n]+1;
    if (start_add[n] >= range[2*n]) {
      start_add[n] = 0;
    }
    else {
      start_add[n] = range[2*n] - start_add[n];
    }
    if (end_add[n] >= range[2*n+1]) {
      end_add[n] = range[2*n+1] - sb->istart[n];
    }
    else {
      end_add[n] = sb->sizes[n];
    }
  }


  int x_size = MAX(0,end_add[0]-start_add[0]);
  int y_size = MAX(0,end_add[1]-start_add[1]);
  int z_size = MAX(0,end_add[2]-start_add[2]);

  int xdim0 = args[0].dat->block_size[0]*args[0].dat->dim;
  int ydim0 = args[0].dat->block_size[1];
  int xdim1 = args[1].dat->block_size[0]*args[1].dat->dim;
  int ydim1 = args[1].dat->block_size[1];
  int xdim2 = args[2].dat->block_size[0]*args[2].dat->dim;
  int ydim2 = args[2].dat->block_size[1];


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(130,"initialise_chunk_kernel_x");
  ops_timers_core(&c2,&t2);

  if (OPS_kernels[130].count == 0) {
    cudaMemcpyToSymbol( xdim0_initialise_chunk_kernel_x, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( ydim0_initialise_chunk_kernel_x, &ydim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_initialise_chunk_kernel_x, &xdim1, sizeof(int) );
    cudaMemcpyToSymbol( ydim1_initialise_chunk_kernel_x, &ydim1, sizeof(int) );
    cudaMemcpyToSymbol( xdim2_initialise_chunk_kernel_x, &xdim2, sizeof(int) );
    cudaMemcpyToSymbol( ydim2_initialise_chunk_kernel_x, &ydim2, sizeof(int) );
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, z_size);
  dim3 block(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = args[0].dat->size;
  int dat1 = args[1].dat->size;
  int dat2 = args[2].dat->size;

  char *p_a[3];

  //set up initial pointers
  int base0 = dat0 * 1 * 
  (start_add[0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0+ dat0 *
    args[0].dat->block_size[0] *
    (start_add[1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  base0 = base0+ dat0 *
    args[0].dat->block_size[0] *
    args[0].dat->block_size[1] *
    (start_add[2] * args[0].stencil->stride[2] - args[0].dat->offset[2]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = dat1 * 1 * 
  (start_add[0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1+ dat1 *
    args[1].dat->block_size[0] *
    (start_add[1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  base1 = base1+ dat1 *
    args[1].dat->block_size[0] *
    args[1].dat->block_size[1] *
    (start_add[2] * args[1].stencil->stride[2] - args[1].dat->offset[2]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base2 = dat2 * 1 * 
  (start_add[0] * args[2].stencil->stride[0] - args[2].dat->offset[0]);
  base2 = base2+ dat2 *
    args[2].dat->block_size[0] *
    (start_add[1] * args[2].stencil->stride[1] - args[2].dat->offset[1]);
  base2 = base2+ dat2 *
    args[2].dat->block_size[0] *
    args[2].dat->block_size[1] *
    (start_add[2] * args[2].stencil->stride[2] - args[2].dat->offset[2]);
  p_a[2] = (char *)args[2].data_d + base2;


  ops_H_D_exchanges_cuda(args, 3);
  ops_halo_exchanges(args,3,range);

  ops_timers_core(&c1,&t1);
  OPS_kernels[130].mpi_time += t1-t2;


  //call kernel wrapper function, passing in pointers to data
  ops_initialise_chunk_kernel_x<<<grid, block >>> (  (double *)p_a[0], (int *)p_a[1],
           (double *)p_a[2],x_size, y_size, z_size);

  if (OPS_diags>1) cutilSafeCall(cudaDeviceSynchronize());
  ops_timers_core(&c2,&t2);
  OPS_kernels[130].time += t2-t1;
  ops_set_dirtybit_cuda(args, 3);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[2],range);

  //Update kernel record
  OPS_kernels[130].count++;
  OPS_kernels[130].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[130].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[130].transfer += ops_compute_transfer(dim, range, &arg2);
}
