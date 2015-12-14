//
// auto-generated by ops.py
//
#include "./OpenACC/shsgc_common.h"

#define OPS_GPU

extern int xdim0_checkop_kernel;
int xdim0_checkop_kernel_h = -1;
extern int xdim1_checkop_kernel;
int xdim1_checkop_kernel_h = -1;
extern int xdim2_checkop_kernel;
int xdim2_checkop_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void checkop_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  int *p_a5,
  int x_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_checkop_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,6,range,14)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(14,"checkop_kernel");
    OPS_kernels[14].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute localy allocated range for the sub-block

  int start[1];
  int end[1];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<1; n++ ){
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
  #else //OPS_MPI
  for ( int n=0; n<1; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif //OPS_MPI

  int x_size = MAX(0,end[0]-start[0]);


  xdim0 = args[0].dat->size[0];
  xdim1 = args[1].dat->size[0];
  xdim2 = args[2].dat->size[0];
  if (xdim0 != xdim0_checkop_kernel_h || xdim1 != xdim1_checkop_kernel_h || xdim2 != xdim2_checkop_kernel_h) {
    xdim0_checkop_kernel = xdim0;
    xdim0_checkop_kernel_h = xdim0;
    xdim1_checkop_kernel = xdim1;
    xdim1_checkop_kernel_h = xdim1;
    xdim2_checkop_kernel = xdim2;
    xdim2_checkop_kernel_h = xdim2;
  }

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;

  #ifdef OPS_MPI
  double *arg3h = (double *)(((ops_reduction)args[3].data)->data + ((ops_reduction)args[3].data)->size * block->index);
  #else //OPS_MPI
  double *arg3h = (double *)(((ops_reduction)args[3].data)->data);
  #endif //OPS_MPI
  #ifdef OPS_MPI
  double *arg4h = (double *)(((ops_reduction)args[4].data)->data + ((ops_reduction)args[4].data)->size * block->index);
  #else //OPS_MPI
  double *arg4h = (double *)(((ops_reduction)args[4].data)->data);
  #endif //OPS_MPI
  #ifdef OPS_MPI
  int *arg5h = (int *)(((ops_reduction)args[5].data)->data + ((ops_reduction)args[5].data)->size * block->index);
  #else //OPS_MPI
  int *arg5h = (int *)(((ops_reduction)args[5].data)->data);
  #endif //OPS_MPI

  //set up initial pointers
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif //OPS_MPI
  int base0 = dat0 * 1 *
    (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d];
  #endif //OPS_MPI
  int base1 = dat1 * 1 *
    (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - d_m[0]);
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d];
  #endif //OPS_MPI
  int base2 = dat2 * 1 *
    (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - d_m[0]);
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  double *p_a3 = arg3h;
  double *p_a4 = arg4h;
  int *p_a5 = arg5h;

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 6);
  #else
  ops_H_D_exchanges_host(args, 6);
  #endif
  ops_halo_exchanges(args,6,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 6);
  #else
  ops_H_D_exchanges_host(args, 6);
  #endif
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[14].mpi_time += t2-t1;
  }

  checkop_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    x_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[14].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 6);
  #else
  ops_set_dirtybit_host(args, 6);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[14].mpi_time += t2-t1;
    OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg0);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg1);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg2);
  }
}
