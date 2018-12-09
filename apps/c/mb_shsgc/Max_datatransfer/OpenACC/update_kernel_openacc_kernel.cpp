//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_update_kernel;
int xdim0_update_kernel_h = -1;
extern int xdim1_update_kernel;
int xdim1_update_kernel_h = -1;
extern int xdim2_update_kernel;
int xdim2_update_kernel_h = -1;
extern int xdim3_update_kernel;
int xdim3_update_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void update_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_update_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[4] = { arg0, arg1, arg2, arg3};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,4,range,13)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(13,"update_kernel");
    OPS_kernels[13].count++;
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
  #else
  for ( int n=0; n<1; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);


  xdim0 = args[0].dat->size[0];
  xdim1 = args[1].dat->size[0];
  xdim2 = args[2].dat->size[0];
  xdim3 = args[3].dat->size[0];
  if (xdim0 != xdim0_update_kernel_h || xdim1 != xdim1_update_kernel_h || xdim2 != xdim2_update_kernel_h || xdim3 != xdim3_update_kernel_h) {
    xdim0_update_kernel = xdim0;
    xdim0_update_kernel_h = xdim0;
    xdim1_update_kernel = xdim1;
    xdim1_update_kernel_h = xdim1;
    xdim2_update_kernel = xdim2;
    xdim2_update_kernel_h = xdim2;
    xdim3_update_kernel = xdim3;
    xdim3_update_kernel_h = xdim3;
  }



  //set up initial pointers
  int base0 = args[0].dat->base_offset + (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  int base1 = args[1].dat->base_offset + (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  int base2 = args[2].dat->base_offset + (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  int base3 = args[3].dat->base_offset + (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif


  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 4);
  #else
  ops_H_D_exchanges_host(args, 4);
  #endif
  ops_halo_exchanges(args,4,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 4);
  #else
  ops_H_D_exchanges_host(args, 4);
  #endif
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[13].mpi_time += t2-t1;
  }

  update_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    x_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[13].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 4);
  #else
  ops_set_dirtybit_host(args, 4);
  #endif
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[13].mpi_time += t2-t1;
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[13].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}
