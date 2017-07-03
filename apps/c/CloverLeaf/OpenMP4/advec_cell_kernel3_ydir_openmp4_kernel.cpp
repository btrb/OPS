//
// auto-generated by ops.py
//
#include "./OpenMP4/advec_cell_kernel3_ydir_openmp4_kernel_c.c"
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

int xdim0_advec_cell_kernel3_ydir;
int xdim0_advec_cell_kernel3_ydir_h = -1;
int xdim1_advec_cell_kernel3_ydir;
int xdim1_advec_cell_kernel3_ydir_h = -1;
int xdim2_advec_cell_kernel3_ydir;
int xdim2_advec_cell_kernel3_ydir_h = -1;
int xdim3_advec_cell_kernel3_ydir;
int xdim3_advec_cell_kernel3_ydir_h = -1;
int xdim4_advec_cell_kernel3_ydir;
int xdim4_advec_cell_kernel3_ydir_h = -1;
int xdim5_advec_cell_kernel3_ydir;
int xdim5_advec_cell_kernel3_ydir_h = -1;
int xdim6_advec_cell_kernel3_ydir;
int xdim6_advec_cell_kernel3_ydir_h = -1;
int xdim7_advec_cell_kernel3_ydir;
int xdim7_advec_cell_kernel3_ydir_h = -1;

void ops_par_loop_advec_cell_kernel3_ydir(char const *name, ops_block block,
                                          int dim, int *range, ops_arg arg0,
                                          ops_arg arg1, ops_arg arg2,
                                          ops_arg arg3, ops_arg arg4,
                                          ops_arg arg5, ops_arg arg6,
                                          ops_arg arg7) {

  // Timing
  double t1, t2, c1, c2;
  ops_arg args[8] = {arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 8, range, 13))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(13, "advec_cell_kernel3_ydir");
    OPS_kernels[13].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute localy allocated range for the sub-block

  int start[2];
  int end[2];
#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 2; n++) {
    start[n] = sb->decomp_disp[n];
    end[n] = sb->decomp_disp[n] + sb->decomp_size[n];
    if (start[n] >= range[2 * n]) {
      start[n] = 0;
    } else {
      start[n] = range[2 * n] - start[n];
    }
    if (sb->id_m[n] == MPI_PROC_NULL && range[2 * n] < 0)
      start[n] = range[2 * n];
    if (end[n] >= range[2 * n + 1]) {
      end[n] = range[2 * n + 1] - sb->decomp_disp[n];
    } else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n] == MPI_PROC_NULL &&
        (range[2 * n + 1] > sb->decomp_disp[n] + sb->decomp_size[n]))
      end[n] += (range[2 * n + 1] - sb->decomp_disp[n] - sb->decomp_size[n]);
  }
#else
  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);

  xdim0 = args[0].dat->size[0];
  xdim1 = args[1].dat->size[0];
  xdim2 = args[2].dat->size[0];
  xdim3 = args[3].dat->size[0];
  xdim4 = args[4].dat->size[0];
  xdim5 = args[5].dat->size[0];
  xdim6 = args[6].dat->size[0];
  xdim7 = args[7].dat->size[0];
  if (xdim0 != xdim0_advec_cell_kernel3_ydir_h ||
      xdim1 != xdim1_advec_cell_kernel3_ydir_h ||
      xdim2 != xdim2_advec_cell_kernel3_ydir_h ||
      xdim3 != xdim3_advec_cell_kernel3_ydir_h ||
      xdim4 != xdim4_advec_cell_kernel3_ydir_h ||
      xdim5 != xdim5_advec_cell_kernel3_ydir_h ||
      xdim6 != xdim6_advec_cell_kernel3_ydir_h ||
      xdim7 != xdim7_advec_cell_kernel3_ydir_h) {
    xdim0_advec_cell_kernel3_ydir = xdim0;
    xdim0_advec_cell_kernel3_ydir_h = xdim0;
    xdim1_advec_cell_kernel3_ydir = xdim1;
    xdim1_advec_cell_kernel3_ydir_h = xdim1;
    xdim2_advec_cell_kernel3_ydir = xdim2;
    xdim2_advec_cell_kernel3_ydir_h = xdim2;
    xdim3_advec_cell_kernel3_ydir = xdim3;
    xdim3_advec_cell_kernel3_ydir_h = xdim3;
    xdim4_advec_cell_kernel3_ydir = xdim4;
    xdim4_advec_cell_kernel3_ydir_h = xdim4;
    xdim5_advec_cell_kernel3_ydir = xdim5;
    xdim5_advec_cell_kernel3_ydir_h = xdim5;
    xdim6_advec_cell_kernel3_ydir = xdim6;
    xdim6_advec_cell_kernel3_ydir_h = xdim6;
    xdim7_advec_cell_kernel3_ydir = xdim7;
    xdim7_advec_cell_kernel3_ydir_h = xdim7;
  }

  int tot0 = 1;
  for (int i = 0; i < args[0].dat->block->dims; i++)
    tot0 = tot0 * args[0].dat->size[i];
  int tot1 = 1;
  for (int i = 0; i < args[1].dat->block->dims; i++)
    tot1 = tot1 * args[1].dat->size[i];
  int tot2 = 1;
  for (int i = 0; i < args[2].dat->block->dims; i++)
    tot2 = tot2 * args[2].dat->size[i];
  int tot3 = 1;
  for (int i = 0; i < args[3].dat->block->dims; i++)
    tot3 = tot3 * args[3].dat->size[i];
  int tot4 = 1;
  for (int i = 0; i < args[4].dat->block->dims; i++)
    tot4 = tot4 * args[4].dat->size[i];
  int tot5 = 1;
  for (int i = 0; i < args[5].dat->block->dims; i++)
    tot5 = tot5 * args[5].dat->size[i];
  int tot6 = 1;
  for (int i = 0; i < args[6].dat->block->dims; i++)
    tot6 = tot6 * args[6].dat->size[i];
  int tot7 = 1;
  for (int i = 0; i < args[7].dat->block->dims; i++)
    tot7 = tot7 * args[7].dat->size[i];

  // set up initial pointers
  int base0 = args[0].dat->base_offset +
              args[0].dat->elem_size * start[0] * args[0].stencil->stride[0];
  base0 = base0 +
          args[0].dat->elem_size * args[0].dat->size[0] * start[1] *
              args[0].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data);
#else
  double *p_a0 = (double *)((char *)args[0].data + base0);
#endif

  int base1 = args[1].dat->base_offset +
              args[1].dat->elem_size * start[0] * args[1].stencil->stride[0];
  base1 = base1 +
          args[1].dat->elem_size * args[1].dat->size[0] * start[1] *
              args[1].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data);
#else
  double *p_a1 = (double *)((char *)args[1].data + base1);
#endif

  int base2 = args[2].dat->base_offset +
              args[2].dat->elem_size * start[0] * args[2].stencil->stride[0];
  base2 = base2 +
          args[2].dat->elem_size * args[2].dat->size[0] * start[1] *
              args[2].stencil->stride[1];
#ifdef OPS_GPU
  int *p_a2 = (int *)((char *)args[2].data);
#else
  int *p_a2 = (int *)((char *)args[2].data + base2);
#endif

  int base3 = args[3].dat->base_offset +
              args[3].dat->elem_size * start[0] * args[3].stencil->stride[0];
  base3 = base3 +
          args[3].dat->elem_size * args[3].dat->size[0] * start[1] *
              args[3].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data);
#else
  double *p_a3 = (double *)((char *)args[3].data + base3);
#endif

  int base4 = args[4].dat->base_offset +
              args[4].dat->elem_size * start[0] * args[4].stencil->stride[0];
  base4 = base4 +
          args[4].dat->elem_size * args[4].dat->size[0] * start[1] *
              args[4].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data);
#else
  double *p_a4 = (double *)((char *)args[4].data + base4);
#endif

  int base5 = args[5].dat->base_offset +
              args[5].dat->elem_size * start[0] * args[5].stencil->stride[0];
  base5 = base5 +
          args[5].dat->elem_size * args[5].dat->size[0] * start[1] *
              args[5].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a5 = (double *)((char *)args[5].data);
#else
  double *p_a5 = (double *)((char *)args[5].data + base5);
#endif

  int base6 = args[6].dat->base_offset +
              args[6].dat->elem_size * start[0] * args[6].stencil->stride[0];
  base6 = base6 +
          args[6].dat->elem_size * args[6].dat->size[0] * start[1] *
              args[6].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a6 = (double *)((char *)args[6].data);
#else
  double *p_a6 = (double *)((char *)args[6].data + base6);
#endif

  int base7 = args[7].dat->base_offset +
              args[7].dat->elem_size * start[0] * args[7].stencil->stride[0];
  base7 = base7 +
          args[7].dat->elem_size * args[7].dat->size[0] * start[1] *
              args[7].stencil->stride[1];
#ifdef OPS_GPU
  double *p_a7 = (double *)((char *)args[7].data);
#else
  double *p_a7 = (double *)((char *)args[7].data + base7);
#endif

#ifdef OPS_GPU
  for (int n = 0; n < 8; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 1) {
      int size = 1;
      for (int i = 0; i < args[n].dat->block->dims; i++)
        size += size * args[n].dat->size[i];
#pragma omp target update to(args[n].dat->data[0 : size])
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_device(args, 8);
#else
  for (int n = 0; n < 8; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 2) {
      int size = 1;
      for (int i = 0; i < args[n].dat->block->dims; i++)
        size += size * args[n].dat->size[i];
#pragma omp target update from(args[n].dat->data[0 : size])
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_host(args, 8);
#endif
  ops_halo_exchanges(args, 8, range);

#ifdef OPS_GPU
// ops_H_D_exchanges_device(args, 8);
#else
// ops_H_D_exchanges_host(args, 8);
#endif
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[13].mpi_time += t2 - t1;
  }

  advec_cell_kernel3_ydir_c_wrapper(p_a0, base0 / args[0].dat->elem_size, tot0,
                                    p_a1, base1 / args[1].dat->elem_size, tot1,
                                    p_a2, base2 / args[2].dat->elem_size, tot2,
                                    p_a3, base3 / args[3].dat->elem_size, tot3,
                                    p_a4, base4 / args[4].dat->elem_size, tot4,
                                    p_a5, base5 / args[5].dat->elem_size, tot5,
                                    p_a6, base6 / args[6].dat->elem_size, tot6,
                                    p_a7, base7 / args[7].dat->elem_size, tot7,
                                    x_size, y_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[13].time += t1 - t2;
  }
#ifdef OPS_GPU
  // for (int n = 0; n < 8; n++) {
  // if ((args[n].argtype == OPS_ARG_DAT) &&
  //(args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
  // args[n].acc == OPS_RW)) {
  // args[n].dat->dirty_hd = 2;
  //}
  //}
  ops_set_dirtybit_device(args, 8);
#else
  // for (int n = 0; n < 8; n++) {
  // if ((args[n].argtype == OPS_ARG_DAT) &&
  //(args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
  // args[n].acc == OPS_RW)) {
  // args[n].dat->dirty_hd = 1;
  //}
  //}
  ops_set_dirtybit_host(args, 8);
#endif
  ops_set_halo_dirtybit3(&args[6], range);
  ops_set_halo_dirtybit3(&args[7], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[13].mpi_time += t2 - t1;
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg7);
  }
}
