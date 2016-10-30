//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y) (n_x*1+n_y*xdim0_tea_leaf_init_zero_kernel*1+x+xdim0_tea_leaf_init_zero_kernel*(y))


//user function

// host stub function
void ops_par_loop_tea_leaf_init_zero_kernel_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[1] = { arg0};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,1,range,45)) return;
  #endif

  if (OPS_diags > 1) {
    OPS_kernels[45].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "tea_leaf_init_zero_kernel");
  #endif



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ p = (double *)(args[0].data + base0);


  //initialize global variable with the dimension of dats
  int xdim0_tea_leaf_init_zero_kernel = args[0].dat->size[0];

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[45].mpi_time += t1-t2;
  }

  #pragma omp parallel for
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #ifdef intel
    #pragma omp simd
    #else
    #pragma simd
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      
  p[OPS_ACC0(0,0)] = 0.0;

    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[45].time += t2-t1;
  }

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c1,&t1);
    OPS_kernels[45].mpi_time += t1-t2;
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
#undef OPS_ACC0


void ops_par_loop_tea_leaf_init_zero_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 45;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 45;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
  }
  desc->nargs = 1;
  desc->args = (ops_arg*)malloc(1*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->function = ops_par_loop_tea_leaf_init_zero_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(45,"tea_leaf_init_zero_kernel");
  }
  ops_enqueue_kernel(desc);
  }
