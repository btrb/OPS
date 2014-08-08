//
// auto-generated by ops.py on 2014-08-08 13:40
//

#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_calc_dt_kernel_min;
extern int ydim0_calc_dt_kernel_min;

#ifdef __cplusplus
extern "C" {
#endif
void calc_dt_kernel_min_c_wrapper(
  double *p_a0,
  double *p_a1,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_calc_dt_kernel_min(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {

  ops_arg args[2] = { arg0, arg1};

  //compute localy allocated range for the sub-block
  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  for ( int n=0; n<3; n++ ){
    start[n] = sb->decomp_disp[n];end[n] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      end[n] = sb->decomp_size[n];
    }
  }
  #else //OPS_MPI
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif //OPS_MPI

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);



  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(38,"calc_dt_kernel_min");
  ops_timers_core(&c2,&t2);

  if (OPS_kernels[38].count == 0) {
    xdim0_calc_dt_kernel_min = args[0].dat->size[0]*args[0].dat->dim;
    ydim0_calc_dt_kernel_min = args[0].dat->size[1];
  }

  int dat0 = args[0].dat->elem_size;


  //set up initial pointers
  int base0 = dat0 * 1 * 
    (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - args[0].dat->d_m[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - args[0].dat->d_m[1]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    (start[2] * args[0].stencil->stride[2] - args[0].dat->base[2] - args[0].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  double *p_a1 = (double *)args[1].data;


  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 2);
  #else
  ops_H_D_exchanges_host(args, 2);
  #endif
  ops_halo_exchanges(args,2,range);

  ops_timers_core(&c1,&t1);
  OPS_kernels[38].mpi_time += t1-t2;

  calc_dt_kernel_min_c_wrapper(
    p_a0,
    p_a1,
    x_size, y_size, z_size);
  *(double *)args[1].data = *p_a1;

  ops_timers_core(&c2,&t2);
  OPS_kernels[38].time += t2-t1;
  ops_mpi_reduce(&arg1,(double *)args[1].data);
  ops_timers_core(&c1,&t1);
  OPS_kernels[38].mpi_time += t1-t2;
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 2);
  #else
  ops_set_dirtybit_host(args, 2);
  #endif

  //Update kernel record
  OPS_kernels[38].count++;
  OPS_kernels[38].transfer += ops_compute_transfer(dim, range, &arg0);
}
