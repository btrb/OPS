//
// auto-generated by ops.py on 2014-08-08 13:40
//


#ifdef OCL_FMA_SWITCH_ON
#define OCL_FMA 1
#else
#define OCL_FMA 0
#endif


static bool isbuilt_advec_mom_kernel_x1 = false;

void buildOpenCLKernels_advec_mom_kernel_x1(int xdim0, int ydim0,
 int xdim1, int ydim1,
 int xdim2, int ydim2,
 int xdim3, int ydim3,
 int xdim4, int ydim4,
 int xdim5, int ydim5) {

  //int ocl_fma = OCL_FMA;
  if(!isbuilt_advec_mom_kernel_x1) {
    buildOpenCLKernels();
    //clSafeCall( clUnloadCompiler() );
    cl_int ret;
    char* source_filename[1] = {"./OpenCL/advec_mom_kernel_x1.cl"};

    // Load the kernel source code into the array source_str
    FILE *fid;
    char *source_str[1];
    size_t source_size[1];

    for(int i=0; i<1; i++) {
      fid = fopen(source_filename[i], "r");
      if (!fid) {
        fprintf(stderr, "Can't open the kernel source file!\n");
        exit(1);
      }

      source_str[i] = (char*)malloc(4*0x1000000);
      source_size[i] = fread(source_str[i], 1, 4*0x1000000, fid);
      if(source_size[i] != 4*0x1000000) {
        if (ferror(fid)) {
          printf ("Error while reading kernel source file %s\n", source_filename[i]);
          exit(-1);
        }
        if (feof(fid))
          printf ("Kernel source file %s succesfuly read.\n", source_filename[i]);
          //printf("%s\n",source_str[i]);
      }
      fclose(fid);
    }

    printf("Compiling advec_mom_kernel_x1 %d source -- start \n",OCL_FMA);

      // Create a program from the source
      OPS_opencl_core.program = clCreateProgramWithSource(OPS_opencl_core.context, 1, (const char **) &source_str, (const size_t *) &source_size, &ret);
      clSafeCall( ret );

      // Build the program
      char buildOpts[255*6];
      char* pPath = NULL;
      pPath = getenv ("OPS_INSTALL_PATH");
      if (pPath!=NULL)
        if(OCL_FMA)
          sprintf(buildOpts,"-cl-mad-enable -DOCL_FMA -I%s/include -DOPS_WARPSIZE=%d  -Dxdim0_advec_mom_kernel_x1=%d -Dydim0_advec_mom_kernel_x1=%d -Dxdim1_advec_mom_kernel_x1=%d -Dydim1_advec_mom_kernel_x1=%d -Dxdim2_advec_mom_kernel_x1=%d -Dydim2_advec_mom_kernel_x1=%d -Dxdim3_advec_mom_kernel_x1=%d -Dydim3_advec_mom_kernel_x1=%d -Dxdim4_advec_mom_kernel_x1=%d -Dydim4_advec_mom_kernel_x1=%d -Dxdim5_advec_mom_kernel_x1=%d -Dydim5_advec_mom_kernel_x1=%d", pPath, 32,xdim0, ydim0,xdim1, ydim1,xdim2, ydim2,xdim3, ydim3,xdim4, ydim4,xdim5, ydim5);
        else
          sprintf(buildOpts,"-cl-mad-enable -I%s/include -DOPS_WARPSIZE=%d  -Dxdim0_advec_mom_kernel_x1=%d -Dydim0_advec_mom_kernel_x1=%d -Dxdim1_advec_mom_kernel_x1=%d -Dydim1_advec_mom_kernel_x1=%d -Dxdim2_advec_mom_kernel_x1=%d -Dydim2_advec_mom_kernel_x1=%d -Dxdim3_advec_mom_kernel_x1=%d -Dydim3_advec_mom_kernel_x1=%d -Dxdim4_advec_mom_kernel_x1=%d -Dydim4_advec_mom_kernel_x1=%d -Dxdim5_advec_mom_kernel_x1=%d -Dydim5_advec_mom_kernel_x1=%d", pPath, 32,xdim0, ydim0,xdim1, ydim1,xdim2, ydim2,xdim3, ydim3,xdim4, ydim4,xdim5, ydim5);
      else {
        sprintf("Incorrect OPS_INSTALL_PATH %s\n",pPath);
        exit(EXIT_FAILURE);
      }

      ret = clBuildProgram(OPS_opencl_core.program, 1, &OPS_opencl_core.device_id, buildOpts, NULL, NULL);

      if(ret != CL_SUCCESS) {
        char* build_log;
        size_t log_size;
        clSafeCall( clGetProgramBuildInfo(OPS_opencl_core.program, OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size) );
        build_log = (char*) malloc(log_size+1);
        clSafeCall( clGetProgramBuildInfo(OPS_opencl_core.program, OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, log_size, build_log, NULL) );
        build_log[log_size] = '\0';
        fprintf(stderr, "=============== OpenCL Program Build Info ================\n\n%s", build_log);
        fprintf(stderr, "\n========================================================= \n");
        free(build_log);
        exit(EXIT_FAILURE);
      }
      printf("compiling advec_mom_kernel_x1 -- done\n");

    // Create the OpenCL kernel
    OPS_opencl_core.kernel[19] = clCreateKernel(OPS_opencl_core.program, "ops_advec_mom_kernel_x1", &ret);
    clSafeCall( ret );

    isbuilt_advec_mom_kernel_x1 = true;
  }

}


// host stub function
void ops_par_loop_advec_mom_kernel_x1(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};

  //compute locally allocated range for the sub-block
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


  int xdim0 = args[0].dat->size[0]*args[0].dat->dim;
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0]*args[1].dat->dim;
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0]*args[2].dat->dim;
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0]*args[3].dat->dim;
  int ydim3 = args[3].dat->size[1];
  int xdim4 = args[4].dat->size[0]*args[4].dat->dim;
  int ydim4 = args[4].dat->size[1];
  int xdim5 = args[5].dat->size[0]*args[5].dat->dim;
  int ydim5 = args[5].dat->size[1];

  //build opencl kernel if not already built

  buildOpenCLKernels_advec_mom_kernel_x1(
  xdim0, ydim0,
  xdim1, ydim1,
  xdim2, ydim2,
  xdim3, ydim3,
  xdim4, ydim4,
  xdim5, ydim5);

  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(19,"advec_mom_kernel_x1");
  ops_timers_core(&c2,&t2);

  //set up OpenCL thread blocks
  size_t globalWorkSize[3] = {((x_size-1)/OPS_block_size_x+ 1)*OPS_block_size_x, ((y_size-1)/OPS_block_size_y + 1)*OPS_block_size_y, z_size};
  size_t localWorkSize[3] =  {OPS_block_size_x,OPS_block_size_y,1};




  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;

  //set up initial pointers
  int base0 = 1 * 
  (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - args[0].dat->d_m[0]);
  base0 = base0 + args[0].dat->size[0] *
  (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - args[0].dat->d_m[1]);
  base0 = base0 + args[0].dat->size[0] *  args[0].dat->size[1] *
  (start[2] * args[0].stencil->stride[2] - args[0].dat->base[2] - args[0].dat->d_m[2]);

  int base1 = 1 * 
  (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - args[1].dat->d_m[0]);
  base1 = base1 + args[1].dat->size[0] *
  (start[1] * args[1].stencil->stride[1] - args[1].dat->base[1] - args[1].dat->d_m[1]);
  base1 = base1 + args[1].dat->size[0] *  args[1].dat->size[1] *
  (start[2] * args[1].stencil->stride[2] - args[1].dat->base[2] - args[1].dat->d_m[2]);

  int base2 = 1 * 
  (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - args[2].dat->d_m[0]);
  base2 = base2 + args[2].dat->size[0] *
  (start[1] * args[2].stencil->stride[1] - args[2].dat->base[1] - args[2].dat->d_m[1]);
  base2 = base2 + args[2].dat->size[0] *  args[2].dat->size[1] *
  (start[2] * args[2].stencil->stride[2] - args[2].dat->base[2] - args[2].dat->d_m[2]);

  int base3 = 1 * 
  (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - args[3].dat->d_m[0]);
  base3 = base3 + args[3].dat->size[0] *
  (start[1] * args[3].stencil->stride[1] - args[3].dat->base[1] - args[3].dat->d_m[1]);
  base3 = base3 + args[3].dat->size[0] *  args[3].dat->size[1] *
  (start[2] * args[3].stencil->stride[2] - args[3].dat->base[2] - args[3].dat->d_m[2]);

  int base4 = 1 * 
  (start[0] * args[4].stencil->stride[0] - args[4].dat->base[0] - args[4].dat->d_m[0]);
  base4 = base4 + args[4].dat->size[0] *
  (start[1] * args[4].stencil->stride[1] - args[4].dat->base[1] - args[4].dat->d_m[1]);
  base4 = base4 + args[4].dat->size[0] *  args[4].dat->size[1] *
  (start[2] * args[4].stencil->stride[2] - args[4].dat->base[2] - args[4].dat->d_m[2]);

  int base5 = 1 * 
  (start[0] * args[5].stencil->stride[0] - args[5].dat->base[0] - args[5].dat->d_m[0]);
  base5 = base5 + args[5].dat->size[0] *
  (start[1] * args[5].stencil->stride[1] - args[5].dat->base[1] - args[5].dat->d_m[1]);
  base5 = base5 + args[5].dat->size[0] *  args[5].dat->size[1] *
  (start[2] * args[5].stencil->stride[2] - args[5].dat->base[2] - args[5].dat->d_m[2]);


  ops_H_D_exchanges_device(args, 6);

  ops_timers_core(&c1,&t1);
  OPS_kernels[19].mpi_time += t1-t2;


  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 0, sizeof(cl_mem), (void*) &arg0.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 1, sizeof(cl_mem), (void*) &arg1.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 2, sizeof(cl_mem), (void*) &arg2.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 3, sizeof(cl_mem), (void*) &arg3.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 4, sizeof(cl_mem), (void*) &arg4.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 5, sizeof(cl_mem), (void*) &arg5.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 6, sizeof(cl_int), (void*) &base0 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 7, sizeof(cl_int), (void*) &base1 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 8, sizeof(cl_int), (void*) &base2 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 9, sizeof(cl_int), (void*) &base3 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 10, sizeof(cl_int), (void*) &base4 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 11, sizeof(cl_int), (void*) &base5 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 12, sizeof(cl_int), (void*) &x_size ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 13, sizeof(cl_int), (void*) &y_size ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[19], 14, sizeof(cl_int), (void*) &z_size ));

  //call/enque opencl kernel wrapper function
  clSafeCall( clEnqueueNDRangeKernel(OPS_opencl_core.command_queue, OPS_opencl_core.kernel[19], 3, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL) );
  if (OPS_diags>1) {
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }

  ops_set_dirtybit_device(args, 6);

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[19].count++;
  OPS_kernels[19].time += t2-t1;
  OPS_kernels[19].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[19].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[19].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[19].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[19].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[19].transfer += ops_compute_transfer(dim, range, &arg5);
}
