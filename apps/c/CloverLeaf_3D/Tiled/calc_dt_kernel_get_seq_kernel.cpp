//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y,z) (n_x*1+n_y*xdim0_calc_dt_kernel_get*0+n_z*xdim0_calc_dt_kernel_get*ydim0_calc_dt_kernel_get*0+x+xdim0_calc_dt_kernel_get*(y)+xdim0_calc_dt_kernel_get*ydim0_calc_dt_kernel_get*(z))
#define OPS_ACC1(x,y,z) (n_x*0+n_y*xdim1_calc_dt_kernel_get*1+n_z*xdim1_calc_dt_kernel_get*ydim1_calc_dt_kernel_get*0+x+xdim1_calc_dt_kernel_get*(y)+xdim1_calc_dt_kernel_get*ydim1_calc_dt_kernel_get*(z))
#define OPS_ACC4(x,y,z) (n_x*0+n_y*xdim4_calc_dt_kernel_get*0+n_z*xdim4_calc_dt_kernel_get*ydim4_calc_dt_kernel_get*1+x+xdim4_calc_dt_kernel_get*(y)+xdim4_calc_dt_kernel_get*ydim4_calc_dt_kernel_get*(z))


//user function

// host stub function
void ops_par_loop_calc_dt_kernel_get_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,6,range,39)) return;
  #endif

  if (OPS_diags > 1) {
    OPS_kernels[39].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];

  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "calc_dt_kernel_get");
  #endif



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double * __restrict__ cellx = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double * __restrict__ celly = (double *)(args[1].data + base1);

  #ifdef OPS_MPI
  double * __restrict__ p_a2 = (double *)(((ops_reduction)args[2].data)->data + ((ops_reduction)args[2].data)->size * block->index);
  #else //OPS_MPI
  double * __restrict__ p_a2 = (double *)((ops_reduction)args[2].data)->data;
  #endif //OPS_MPI


  #ifdef OPS_MPI
  double * __restrict__ p_a3 = (double *)(((ops_reduction)args[3].data)->data + ((ops_reduction)args[3].data)->size * block->index);
  #else //OPS_MPI
  double * __restrict__ p_a3 = (double *)((ops_reduction)args[3].data)->data;
  #endif //OPS_MPI


  int base4 = args[4].dat->base_offset;
  const double * __restrict__ cellz = (double *)(args[4].data + base4);

  #ifdef OPS_MPI
  double * __restrict__ p_a5 = (double *)(((ops_reduction)args[5].data)->data + ((ops_reduction)args[5].data)->size * block->index);
  #else //OPS_MPI
  double * __restrict__ p_a5 = (double *)((ops_reduction)args[5].data)->data;
  #endif //OPS_MPI



  //initialize global variable with the dimension of dats
  int xdim0_calc_dt_kernel_get = args[0].dat->size[0];
  int ydim0_calc_dt_kernel_get = args[0].dat->size[1];
  int xdim1_calc_dt_kernel_get = args[1].dat->size[0];
  int ydim1_calc_dt_kernel_get = args[1].dat->size[1];
  int xdim4_calc_dt_kernel_get = args[4].dat->size[0];
  int ydim4_calc_dt_kernel_get = args[4].dat->size[1];

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[39].mpi_time += t1-t2;
  }

  double p_a2_0 = p_a2[0];
  double p_a3_0 = p_a3[0];
  double p_a5_0 = p_a5[0];
  #pragma omp parallel for reduction(+:p_a2_0) reduction(+:p_a3_0) reduction(+:p_a5_0)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef intel
      #pragma omp simd reduction(+:p_a2_0) reduction(+:p_a3_0) reduction(+:p_a5_0)
      #else
      #pragma simd reduction(+:p_a2_0) reduction(+:p_a3_0) reduction(+:p_a5_0)
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        double *xl_pos = &p_a2_0;
        double *yl_pos = &p_a3_0;
        double *zl_pos = &p_a5_0;
        
  *xl_pos = cellx[OPS_ACC0(0,0,0)];
  *yl_pos = celly[OPS_ACC1(0,0,0)];
  *zl_pos = cellz[OPS_ACC4(0,0,0)];

      }
    }
  }
  p_a2[0] = p_a2_0;
  p_a3[0] = p_a3_0;
  p_a5[0] = p_a5_0;
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[39].time += t2-t1;
  }

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c1,&t1);
    OPS_kernels[39].mpi_time += t1-t2;
    OPS_kernels[39].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[39].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[39].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC4


void ops_par_loop_calc_dt_kernel_get(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 39;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 39;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
  }
  desc->nargs = 6;
  desc->args = (ops_arg*)malloc(6*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->args[3] = arg3;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->function = ops_par_loop_calc_dt_kernel_get_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(39,"calc_dt_kernel_get");
  }
  ops_enqueue_kernel(desc);
  }
