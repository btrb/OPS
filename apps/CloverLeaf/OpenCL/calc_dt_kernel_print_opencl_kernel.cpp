//
// auto-generated by ops.py on 2014-06-05 12:48
//


// host stub function
void ops_par_loop_calc_dt_kernel_print(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {

  buildOpenCLKernels();
  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};

  sub_block_list sb = OPS_sub_block_list[Block->index];
  //compute localy allocated range for the sub-block
  int start_add[2];
  int end_add[2];
  for ( int n=0; n<2; n++ ){
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


  int x_size = end_add[0]-start_add[0];
  int y_size = end_add[1]-start_add[1];

  int xdim0 = args[0].dat->block_size[0]*args[0].dat->dim;
  int xdim1 = args[1].dat->block_size[0]*args[1].dat->dim;
  int xdim2 = args[2].dat->block_size[0]*args[2].dat->dim;
  int xdim3 = args[3].dat->block_size[0]*args[3].dat->dim;
  int xdim4 = args[4].dat->block_size[0]*args[4].dat->dim;
  int xdim5 = args[5].dat->block_size[0]*args[5].dat->dim;


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(73,"calc_dt_kernel_print");
  ops_timers_core(&c1,&t1);

  //set up OpenCL thread blocks
  size_t globalWorkSize[3] = {((x_size-1)/OPS_block_size_x+ 1)*OPS_block_size_x, ((y_size-1)/OPS_block_size_y + 1)*OPS_block_size_y, 1};
  size_t localWorkSize[3] =  {OPS_block_size_x,OPS_block_size_y,1};




  int dat0 = args[0].dat->size;
  int dat1 = args[1].dat->size;
  int dat2 = args[2].dat->size;
  int dat3 = args[3].dat->size;
  int dat4 = args[4].dat->size;
  int dat5 = args[5].dat->size;

  //set up initial pointers
  int base0 = dat0 * 1 * 
  (start_add[0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0  + dat0 * args[0].dat->block_size[0] * 
  (start_add[1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  base0 = base0/dat0;

  //set up initial pointers
  int base1 = dat1 * 1 * 
  (start_add[0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1  + dat1 * args[1].dat->block_size[0] * 
  (start_add[1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  base1 = base1/dat1;

  //set up initial pointers
  int base2 = dat2 * 1 * 
  (start_add[0] * args[2].stencil->stride[0] - args[2].dat->offset[0]);
  base2 = base2  + dat2 * args[2].dat->block_size[0] * 
  (start_add[1] * args[2].stencil->stride[1] - args[2].dat->offset[1]);
  base2 = base2/dat2;

  //set up initial pointers
  int base3 = dat3 * 1 * 
  (start_add[0] * args[3].stencil->stride[0] - args[3].dat->offset[0]);
  base3 = base3  + dat3 * args[3].dat->block_size[0] * 
  (start_add[1] * args[3].stencil->stride[1] - args[3].dat->offset[1]);
  base3 = base3/dat3;

  //set up initial pointers
  int base4 = dat4 * 1 * 
  (start_add[0] * args[4].stencil->stride[0] - args[4].dat->offset[0]);
  base4 = base4  + dat4 * args[4].dat->block_size[0] * 
  (start_add[1] * args[4].stencil->stride[1] - args[4].dat->offset[1]);
  base4 = base4/dat4;

  //set up initial pointers
  int base5 = dat5 * 1 * 
  (start_add[0] * args[5].stencil->stride[0] - args[5].dat->offset[0]);
  base5 = base5  + dat5 * args[5].dat->block_size[0] * 
  (start_add[1] * args[5].stencil->stride[1] - args[5].dat->offset[1]);
  base5 = base5/dat5;


  ops_H_D_exchanges_cuda(args, 6);


  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 0, sizeof(cl_mem), (void*) &arg0.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 1, sizeof(cl_mem), (void*) &arg1.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 2, sizeof(cl_mem), (void*) &arg2.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 3, sizeof(cl_mem), (void*) &arg3.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 4, sizeof(cl_mem), (void*) &arg4.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 5, sizeof(cl_mem), (void*) &arg5.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 6, sizeof(cl_int), (void*) &xdim0 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 7, sizeof(cl_int), (void*) &xdim1 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 8, sizeof(cl_int), (void*) &xdim2 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 9, sizeof(cl_int), (void*) &xdim3 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 10, sizeof(cl_int), (void*) &xdim4 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 11, sizeof(cl_int), (void*) &xdim5 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 12, sizeof(cl_int), (void*) &base0 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 13, sizeof(cl_int), (void*) &base1 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 14, sizeof(cl_int), (void*) &base2 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 15, sizeof(cl_int), (void*) &base3 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 16, sizeof(cl_int), (void*) &base4 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 17, sizeof(cl_int), (void*) &base5 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 18, sizeof(cl_int), (void*) &x_size ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[73], 19, sizeof(cl_int), (void*) &y_size ));

  //call/enque opencl kernel wrapper function
  clSafeCall( clEnqueueNDRangeKernel(OPS_opencl_core.command_queue, OPS_opencl_core.kernel[73], 3, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL) );
  clSafeCall( clFinish(OPS_opencl_core.command_queue) );

  ops_set_dirtybit_cuda(args, 6);
  ops_H_D_exchanges(args, 6);

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[73].count++;
  OPS_kernels[73].time += t2-t1;
  OPS_kernels[73].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[73].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[73].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[73].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[73].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[73].transfer += ops_compute_transfer(dim, range, &arg5);
}
