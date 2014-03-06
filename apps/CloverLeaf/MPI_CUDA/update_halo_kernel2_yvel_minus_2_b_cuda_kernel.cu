//
// auto-generated by ops.py on 2014-03-06 15:57
//

__constant__ int xdim0_update_halo_kernel2_yvel_minus_2_b;
__constant__ int xdim1_update_halo_kernel2_yvel_minus_2_b;

#define OPS_ACC0(x,y) (x+xdim0_update_halo_kernel2_yvel_minus_2_b*(y))
#define OPS_ACC1(x,y) (x+xdim1_update_halo_kernel2_yvel_minus_2_b*(y))

//user function
__device__

void update_halo_kernel2_yvel_minus_2_b(double *yvel0, double *yvel1){
  if(fields[FIELD_XVEL0] == 1) yvel0[OPS_ACC0(0,0)] = -yvel0[OPS_ACC0(0,-2)];
  if(fields[FIELD_XVEL1] == 1) yvel1[OPS_ACC1(0,0)] = -yvel1[OPS_ACC1(0,-2)];
}



#undef OPS_ACC0
#undef OPS_ACC1


__global__ void ops_update_halo_kernel2_yvel_minus_2_b(
double* __restrict arg0,
double* __restrict arg1,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 1 * xdim0_update_halo_kernel2_yvel_minus_2_b;
  arg1 += idx_x * 1 + idx_y * 1 * xdim1_update_halo_kernel2_yvel_minus_2_b;

  if (idx_x < size0 && idx_y < size1) {
    update_halo_kernel2_yvel_minus_2_b(arg0, arg1);
  }

}

// host stub function
void ops_par_loop_update_halo_kernel2_yvel_minus_2_b(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {

  ops_arg args[2] = { arg0, arg1};

  sub_block_list sb = OPS_sub_block_list[Block->index];
  //compute localy allocated range for the sub-block
  int ndim = sb->ndim;
  int start_add[ndim*2];
  int end_add[ndim*2];

  int s[ndim];
  int e[ndim];

  for ( int n=0; n<ndim; n++ ){
    s[n] = sb->istart[n];e[n] = sb->iend[n]+1;
    if (s[n] >= range[2*n]) {
      s[n] = 0;
    }
    else {
      s[n] = range[2*n] - s[n];
    }
    if (e[n] >= range[2*n+1]) {
      e[n] = range[2*n+1] - sb->istart[n];
    }
    else {
      e[n] = sb->sizes[n];
    }
  }

  for ( int i=0; i<2; i++ ){
    for ( int n=0; n<ndim; n++ ){
      start_add[i*ndim+n] = s[n];
      end_add[i*ndim+n]   = e[n];
    }
  }


  int x_size = e[0]-s[0];
  int y_size = e[1]-s[1];

  int xdim0 = args[0].dat->block_size[0];
  int xdim1 = args[1].dat->block_size[0];


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(55,"update_halo_kernel2_yvel_minus_2_b");
  ops_timers_core(&c1,&t1);

  if (OPS_kernels[55].count == 0) {
    cudaMemcpyToSymbol( xdim0_update_halo_kernel2_yvel_minus_2_b, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_update_halo_kernel2_yvel_minus_2_b, &xdim1, sizeof(int) );
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 block(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = args[0].dat->size;
  int dat1 = args[1].dat->size;

  char *p_a[2];

  //set up initial pointers
  int base0 = dat0 * 1 * 
  (start_add[ndim+0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0  + dat0 * args[0].dat->block_size[0] * 
  (start_add[ndim+1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  p_a[0] = (char *)args[0].data + base0;

  //set up initial pointers
  int base1 = dat1 * 1 * 
  (start_add[ndim+0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1  + dat1 * args[1].dat->block_size[0] * 
  (start_add[ndim+1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  p_a[1] = (char *)args[1].data + base1;


  ops_H_D_exchanges_cuda(args, 2);


  //call kernel wrapper function, passing in pointers to data
  ops_update_halo_kernel2_yvel_minus_2_b<<<grid, block >>> (  (double *)p_a[0], (double *)p_a[1],x_size, y_size);

  if (OPS_diags>1) cudaDeviceSynchronize();
  ops_set_dirtybit_cuda(args, 2);

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[55].count++;
  OPS_kernels[55].time += t2-t1;
  OPS_kernels[55].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[55].transfer += ops_compute_transfer(dim, range, &arg1);
}
