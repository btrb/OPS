//
// auto-generated by ops.py on 2014-08-08 13:40
//

#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_advec_cell_kernel4_ydir;
extern int ydim0_advec_cell_kernel4_ydir;
extern int xdim1_advec_cell_kernel4_ydir;
extern int ydim1_advec_cell_kernel4_ydir;
extern int xdim2_advec_cell_kernel4_ydir;
extern int ydim2_advec_cell_kernel4_ydir;
extern int xdim3_advec_cell_kernel4_ydir;
extern int ydim3_advec_cell_kernel4_ydir;
extern int xdim4_advec_cell_kernel4_ydir;
extern int ydim4_advec_cell_kernel4_ydir;
extern int xdim5_advec_cell_kernel4_ydir;
extern int ydim5_advec_cell_kernel4_ydir;
extern int xdim6_advec_cell_kernel4_ydir;
extern int ydim6_advec_cell_kernel4_ydir;
extern int xdim7_advec_cell_kernel4_ydir;
extern int ydim7_advec_cell_kernel4_ydir;
extern int xdim8_advec_cell_kernel4_ydir;
extern int ydim8_advec_cell_kernel4_ydir;
extern int xdim9_advec_cell_kernel4_ydir;
extern int ydim9_advec_cell_kernel4_ydir;
extern int xdim10_advec_cell_kernel4_ydir;
extern int ydim10_advec_cell_kernel4_ydir;

#ifdef __cplusplus
extern "C" {
#endif
void advec_cell_kernel4_ydir_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_advec_cell_kernel4_ydir(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10) {

  ops_arg args[11] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10};

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
  ops_timing_realloc(14,"advec_cell_kernel4_ydir");
  ops_timers_core(&c2,&t2);

  if (OPS_kernels[14].count == 0) {
    xdim0_advec_cell_kernel4_ydir = args[0].dat->size[0]*args[0].dat->dim;
    ydim0_advec_cell_kernel4_ydir = args[0].dat->size[1];
    xdim1_advec_cell_kernel4_ydir = args[1].dat->size[0]*args[1].dat->dim;
    ydim1_advec_cell_kernel4_ydir = args[1].dat->size[1];
    xdim2_advec_cell_kernel4_ydir = args[2].dat->size[0]*args[2].dat->dim;
    ydim2_advec_cell_kernel4_ydir = args[2].dat->size[1];
    xdim3_advec_cell_kernel4_ydir = args[3].dat->size[0]*args[3].dat->dim;
    ydim3_advec_cell_kernel4_ydir = args[3].dat->size[1];
    xdim4_advec_cell_kernel4_ydir = args[4].dat->size[0]*args[4].dat->dim;
    ydim4_advec_cell_kernel4_ydir = args[4].dat->size[1];
    xdim5_advec_cell_kernel4_ydir = args[5].dat->size[0]*args[5].dat->dim;
    ydim5_advec_cell_kernel4_ydir = args[5].dat->size[1];
    xdim6_advec_cell_kernel4_ydir = args[6].dat->size[0]*args[6].dat->dim;
    ydim6_advec_cell_kernel4_ydir = args[6].dat->size[1];
    xdim7_advec_cell_kernel4_ydir = args[7].dat->size[0]*args[7].dat->dim;
    ydim7_advec_cell_kernel4_ydir = args[7].dat->size[1];
    xdim8_advec_cell_kernel4_ydir = args[8].dat->size[0]*args[8].dat->dim;
    ydim8_advec_cell_kernel4_ydir = args[8].dat->size[1];
    xdim9_advec_cell_kernel4_ydir = args[9].dat->size[0]*args[9].dat->dim;
    ydim9_advec_cell_kernel4_ydir = args[9].dat->size[1];
    xdim10_advec_cell_kernel4_ydir = args[10].dat->size[0]*args[10].dat->dim;
    ydim10_advec_cell_kernel4_ydir = args[10].dat->size[1];
  }

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;
  int dat6 = args[6].dat->elem_size;
  int dat7 = args[7].dat->elem_size;
  int dat8 = args[8].dat->elem_size;
  int dat9 = args[9].dat->elem_size;
  int dat10 = args[10].dat->elem_size;


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

  int base1 = dat1 * 1 * 
    (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - args[1].dat->d_m[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1] - args[1].dat->base[1] - args[1].dat->d_m[1]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    (start[2] * args[1].stencil->stride[2] - args[1].dat->base[2] - args[1].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  int base2 = dat2 * 1 * 
    (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - args[2].dat->d_m[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1] - args[2].dat->base[1] - args[2].dat->d_m[1]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    (start[2] * args[2].stencil->stride[2] - args[2].dat->base[2] - args[2].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  int base3 = dat3 * 1 * 
    (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - args[3].dat->d_m[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1] - args[3].dat->base[1] - args[3].dat->d_m[1]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    (start[2] * args[3].stencil->stride[2] - args[3].dat->base[2] - args[3].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif

  int base4 = dat4 * 1 * 
    (start[0] * args[4].stencil->stride[0] - args[4].dat->base[0] - args[4].dat->d_m[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1] - args[4].dat->base[1] - args[4].dat->d_m[1]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    (start[2] * args[4].stencil->stride[2] - args[4].dat->base[2] - args[4].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data_d + base4);
  #else
  double *p_a4 = (double *)((char *)args[4].data + base4);
  #endif

  int base5 = dat5 * 1 * 
    (start[0] * args[5].stencil->stride[0] - args[5].dat->base[0] - args[5].dat->d_m[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1] - args[5].dat->base[1] - args[5].dat->d_m[1]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    (start[2] * args[5].stencil->stride[2] - args[5].dat->base[2] - args[5].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a5 = (double *)((char *)args[5].data_d + base5);
  #else
  double *p_a5 = (double *)((char *)args[5].data + base5);
  #endif

  int base6 = dat6 * 1 * 
    (start[0] * args[6].stencil->stride[0] - args[6].dat->base[0] - args[6].dat->d_m[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1] - args[6].dat->base[1] - args[6].dat->d_m[1]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    (start[2] * args[6].stencil->stride[2] - args[6].dat->base[2] - args[6].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a6 = (double *)((char *)args[6].data_d + base6);
  #else
  double *p_a6 = (double *)((char *)args[6].data + base6);
  #endif

  int base7 = dat7 * 1 * 
    (start[0] * args[7].stencil->stride[0] - args[7].dat->base[0] - args[7].dat->d_m[0]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    (start[1] * args[7].stencil->stride[1] - args[7].dat->base[1] - args[7].dat->d_m[1]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    args[7].dat->size[1] *
    (start[2] * args[7].stencil->stride[2] - args[7].dat->base[2] - args[7].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a7 = (double *)((char *)args[7].data_d + base7);
  #else
  double *p_a7 = (double *)((char *)args[7].data + base7);
  #endif

  int base8 = dat8 * 1 * 
    (start[0] * args[8].stencil->stride[0] - args[8].dat->base[0] - args[8].dat->d_m[0]);
  base8 = base8+ dat8 *
    args[8].dat->size[0] *
    (start[1] * args[8].stencil->stride[1] - args[8].dat->base[1] - args[8].dat->d_m[1]);
  base8 = base8+ dat8 *
    args[8].dat->size[0] *
    args[8].dat->size[1] *
    (start[2] * args[8].stencil->stride[2] - args[8].dat->base[2] - args[8].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a8 = (double *)((char *)args[8].data_d + base8);
  #else
  double *p_a8 = (double *)((char *)args[8].data + base8);
  #endif

  int base9 = dat9 * 1 * 
    (start[0] * args[9].stencil->stride[0] - args[9].dat->base[0] - args[9].dat->d_m[0]);
  base9 = base9+ dat9 *
    args[9].dat->size[0] *
    (start[1] * args[9].stencil->stride[1] - args[9].dat->base[1] - args[9].dat->d_m[1]);
  base9 = base9+ dat9 *
    args[9].dat->size[0] *
    args[9].dat->size[1] *
    (start[2] * args[9].stencil->stride[2] - args[9].dat->base[2] - args[9].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a9 = (double *)((char *)args[9].data_d + base9);
  #else
  double *p_a9 = (double *)((char *)args[9].data + base9);
  #endif

  int base10 = dat10 * 1 * 
    (start[0] * args[10].stencil->stride[0] - args[10].dat->base[0] - args[10].dat->d_m[0]);
  base10 = base10+ dat10 *
    args[10].dat->size[0] *
    (start[1] * args[10].stencil->stride[1] - args[10].dat->base[1] - args[10].dat->d_m[1]);
  base10 = base10+ dat10 *
    args[10].dat->size[0] *
    args[10].dat->size[1] *
    (start[2] * args[10].stencil->stride[2] - args[10].dat->base[2] - args[10].dat->d_m[2]);
  #ifdef OPS_GPU
  double *p_a10 = (double *)((char *)args[10].data_d + base10);
  #else
  double *p_a10 = (double *)((char *)args[10].data + base10);
  #endif


  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 11);
  #else
  ops_H_D_exchanges_host(args, 11);
  #endif
  ops_halo_exchanges(args,11,range);

  ops_timers_core(&c1,&t1);
  OPS_kernels[14].mpi_time += t1-t2;

  advec_cell_kernel4_ydir_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    p_a6,
    p_a7,
    p_a8,
    p_a9,
    p_a10,
    x_size, y_size, z_size);

  ops_timers_core(&c2,&t2);
  OPS_kernels[14].time += t2-t1;
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 11);
  #else
  ops_set_dirtybit_host(args, 11);
  #endif
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);
  ops_set_halo_dirtybit3(&args[8],range);
  ops_set_halo_dirtybit3(&args[9],range);

  //Update kernel record
  OPS_kernels[14].count++;
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg5);
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg6);
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg7);
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg8);
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg9);
  OPS_kernels[14].transfer += ops_compute_transfer(dim, range, &arg10);
}
