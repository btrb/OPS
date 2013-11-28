//
// auto-generated by ops.py on 2013-11-28 10:55
//

#include "ops_lib_openmp.h"
#ifdef _OPENMP
#include <omp.h>
#endif
//user function
#include "PdV_kernel.h"

// host stub function
void ops_par_loop_PdV_kernel_nopredict(char const *name, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13) {

  int  offs[14][2];
  ops_arg args[14] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13};

  offs[0][0] = 1;  //unit step in x dimension
  offs[0][1] = ops_offs_set(range[0],range[2]+1, args[0]) - ops_offs_set(range[1],range[2], args[0]);
  if (args[0].stencil->stride[0] == 0) {
    offs[0][0] = 0;
    offs[0][1] = args[0].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[0].stencil->stride[1] == 0) {
    offs[0][0] = 1;
    offs[0][1] = -( range[1] - range[0] );
  }

  offs[1][0] = 1;  //unit step in x dimension
  offs[1][1] = ops_offs_set(range[0],range[2]+1, args[1]) - ops_offs_set(range[1],range[2], args[1]);
  if (args[1].stencil->stride[0] == 0) {
    offs[1][0] = 0;
    offs[1][1] = args[1].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[1].stencil->stride[1] == 0) {
    offs[1][0] = 1;
    offs[1][1] = -( range[1] - range[0] );
  }

  offs[2][0] = 1;  //unit step in x dimension
  offs[2][1] = ops_offs_set(range[0],range[2]+1, args[2]) - ops_offs_set(range[1],range[2], args[2]);
  if (args[2].stencil->stride[0] == 0) {
    offs[2][0] = 0;
    offs[2][1] = args[2].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[2].stencil->stride[1] == 0) {
    offs[2][0] = 1;
    offs[2][1] = -( range[1] - range[0] );
  }

  offs[3][0] = 1;  //unit step in x dimension
  offs[3][1] = ops_offs_set(range[0],range[2]+1, args[3]) - ops_offs_set(range[1],range[2], args[3]);
  if (args[3].stencil->stride[0] == 0) {
    offs[3][0] = 0;
    offs[3][1] = args[3].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[3].stencil->stride[1] == 0) {
    offs[3][0] = 1;
    offs[3][1] = -( range[1] - range[0] );
  }

  offs[4][0] = 1;  //unit step in x dimension
  offs[4][1] = ops_offs_set(range[0],range[2]+1, args[4]) - ops_offs_set(range[1],range[2], args[4]);
  if (args[4].stencil->stride[0] == 0) {
    offs[4][0] = 0;
    offs[4][1] = args[4].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[4].stencil->stride[1] == 0) {
    offs[4][0] = 1;
    offs[4][1] = -( range[1] - range[0] );
  }

  offs[5][0] = 1;  //unit step in x dimension
  offs[5][1] = ops_offs_set(range[0],range[2]+1, args[5]) - ops_offs_set(range[1],range[2], args[5]);
  if (args[5].stencil->stride[0] == 0) {
    offs[5][0] = 0;
    offs[5][1] = args[5].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[5].stencil->stride[1] == 0) {
    offs[5][0] = 1;
    offs[5][1] = -( range[1] - range[0] );
  }

  offs[6][0] = 1;  //unit step in x dimension
  offs[6][1] = ops_offs_set(range[0],range[2]+1, args[6]) - ops_offs_set(range[1],range[2], args[6]);
  if (args[6].stencil->stride[0] == 0) {
    offs[6][0] = 0;
    offs[6][1] = args[6].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[6].stencil->stride[1] == 0) {
    offs[6][0] = 1;
    offs[6][1] = -( range[1] - range[0] );
  }

  offs[7][0] = 1;  //unit step in x dimension
  offs[7][1] = ops_offs_set(range[0],range[2]+1, args[7]) - ops_offs_set(range[1],range[2], args[7]);
  if (args[7].stencil->stride[0] == 0) {
    offs[7][0] = 0;
    offs[7][1] = args[7].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[7].stencil->stride[1] == 0) {
    offs[7][0] = 1;
    offs[7][1] = -( range[1] - range[0] );
  }

  offs[8][0] = 1;  //unit step in x dimension
  offs[8][1] = ops_offs_set(range[0],range[2]+1, args[8]) - ops_offs_set(range[1],range[2], args[8]);
  if (args[8].stencil->stride[0] == 0) {
    offs[8][0] = 0;
    offs[8][1] = args[8].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[8].stencil->stride[1] == 0) {
    offs[8][0] = 1;
    offs[8][1] = -( range[1] - range[0] );
  }

  offs[9][0] = 1;  //unit step in x dimension
  offs[9][1] = ops_offs_set(range[0],range[2]+1, args[9]) - ops_offs_set(range[1],range[2], args[9]);
  if (args[9].stencil->stride[0] == 0) {
    offs[9][0] = 0;
    offs[9][1] = args[9].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[9].stencil->stride[1] == 0) {
    offs[9][0] = 1;
    offs[9][1] = -( range[1] - range[0] );
  }

  offs[10][0] = 1;  //unit step in x dimension
  offs[10][1] = ops_offs_set(range[0],range[2]+1, args[10]) - ops_offs_set(range[1],range[2], args[10]);
  if (args[10].stencil->stride[0] == 0) {
    offs[10][0] = 0;
    offs[10][1] = args[10].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[10].stencil->stride[1] == 0) {
    offs[10][0] = 1;
    offs[10][1] = -( range[1] - range[0] );
  }

  offs[11][0] = 1;  //unit step in x dimension
  offs[11][1] = ops_offs_set(range[0],range[2]+1, args[11]) - ops_offs_set(range[1],range[2], args[11]);
  if (args[11].stencil->stride[0] == 0) {
    offs[11][0] = 0;
    offs[11][1] = args[11].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[11].stencil->stride[1] == 0) {
    offs[11][0] = 1;
    offs[11][1] = -( range[1] - range[0] );
  }

  offs[12][0] = 1;  //unit step in x dimension
  offs[12][1] = ops_offs_set(range[0],range[2]+1, args[12]) - ops_offs_set(range[1],range[2], args[12]);
  if (args[12].stencil->stride[0] == 0) {
    offs[12][0] = 0;
    offs[12][1] = args[12].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[12].stencil->stride[1] == 0) {
    offs[12][0] = 1;
    offs[12][1] = -( range[1] - range[0] );
  }

  offs[13][0] = 1;  //unit step in x dimension
  offs[13][1] = ops_offs_set(range[0],range[2]+1, args[13]) - ops_offs_set(range[1],range[2], args[13]);
  if (args[13].stencil->stride[0] == 0) {
    offs[13][0] = 0;
    offs[13][1] = args[13].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[13].stencil->stride[1] == 0) {
    offs[13][0] = 1;
    offs[13][1] = -( range[1] - range[0] );
  }

  int off0_1 = offs[0][0];
  int off0_2 = offs[0][1];
  int dat0 = args[0].dat->size;
  int off1_1 = offs[1][0];
  int off1_2 = offs[1][1];
  int dat1 = args[1].dat->size;
  int off2_1 = offs[2][0];
  int off2_2 = offs[2][1];
  int dat2 = args[2].dat->size;
  int off3_1 = offs[3][0];
  int off3_2 = offs[3][1];
  int dat3 = args[3].dat->size;
  int off4_1 = offs[4][0];
  int off4_2 = offs[4][1];
  int dat4 = args[4].dat->size;
  int off5_1 = offs[5][0];
  int off5_2 = offs[5][1];
  int dat5 = args[5].dat->size;
  int off6_1 = offs[6][0];
  int off6_2 = offs[6][1];
  int dat6 = args[6].dat->size;
  int off7_1 = offs[7][0];
  int off7_2 = offs[7][1];
  int dat7 = args[7].dat->size;
  int off8_1 = offs[8][0];
  int off8_2 = offs[8][1];
  int dat8 = args[8].dat->size;
  int off9_1 = offs[9][0];
  int off9_2 = offs[9][1];
  int dat9 = args[9].dat->size;
  int off10_1 = offs[10][0];
  int off10_2 = offs[10][1];
  int dat10 = args[10].dat->size;
  int off11_1 = offs[11][0];
  int off11_2 = offs[11][1];
  int dat11 = args[11].dat->size;
  int off12_1 = offs[12][0];
  int off12_2 = offs[12][1];
  int dat12 = args[12].dat->size;
  int off13_1 = offs[13][0];
  int off13_2 = offs[13][1];
  int dat13 = args[13].dat->size;


  #ifdef _OPENMP
  int nthreads = omp_get_max_threads( );
  #else
  int nthreads = 1;
  #endif


  int y_size = range[3]-range[2];

  xdim0 = args[0].dat->block_size[0];
  xdim1 = args[1].dat->block_size[0];
  xdim2 = args[2].dat->block_size[0];
  xdim3 = args[3].dat->block_size[0];
  xdim4 = args[4].dat->block_size[0];
  xdim5 = args[5].dat->block_size[0];
  xdim6 = args[6].dat->block_size[0];
  xdim7 = args[7].dat->block_size[0];
  xdim8 = args[8].dat->block_size[0];
  xdim9 = args[9].dat->block_size[0];
  xdim10 = args[10].dat->block_size[0];
  xdim11 = args[11].dat->block_size[0];
  xdim12 = args[12].dat->block_size[0];
  xdim13 = args[13].dat->block_size[0];


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(81,"PdV_kernel_nopredict");
  ops_timers_core(&c1,&t1);

  ops_halo_exchanges(args, 14);

  #pragma omp parallel for
  for ( int thr=0; thr<nthreads; thr++ ){

    char *p_a[14];

    int start = range[2] + ((y_size-1)/nthreads+1)*thr;
    int finish = range[2] +  MIN(((y_size-1)/nthreads+1)*(thr+1),y_size);

    //set up initial pointers
    p_a[0] = &args[0].data[
    + args[0].dat->size * args[0].dat->block_size[0] * ( start * 1 - args[0].dat->offset[1] )
    + args[0].dat->size * ( range[0] * 1 - args[0].dat->offset[0] ) ];

    p_a[1] = &args[1].data[
    + args[1].dat->size * args[1].dat->block_size[0] * ( start * 1 - args[1].dat->offset[1] )
    + args[1].dat->size * ( range[0] * 1 - args[1].dat->offset[0] ) ];

    p_a[2] = &args[2].data[
    + args[2].dat->size * args[2].dat->block_size[0] * ( start * 1 - args[2].dat->offset[1] )
    + args[2].dat->size * ( range[0] * 1 - args[2].dat->offset[0] ) ];

    p_a[3] = &args[3].data[
    + args[3].dat->size * args[3].dat->block_size[0] * ( start * 1 - args[3].dat->offset[1] )
    + args[3].dat->size * ( range[0] * 1 - args[3].dat->offset[0] ) ];

    p_a[4] = &args[4].data[
    + args[4].dat->size * args[4].dat->block_size[0] * ( start * 1 - args[4].dat->offset[1] )
    + args[4].dat->size * ( range[0] * 1 - args[4].dat->offset[0] ) ];

    p_a[5] = &args[5].data[
    + args[5].dat->size * args[5].dat->block_size[0] * ( start * 1 - args[5].dat->offset[1] )
    + args[5].dat->size * ( range[0] * 1 - args[5].dat->offset[0] ) ];

    p_a[6] = &args[6].data[
    + args[6].dat->size * args[6].dat->block_size[0] * ( start * 1 - args[6].dat->offset[1] )
    + args[6].dat->size * ( range[0] * 1 - args[6].dat->offset[0] ) ];

    p_a[7] = &args[7].data[
    + args[7].dat->size * args[7].dat->block_size[0] * ( start * 1 - args[7].dat->offset[1] )
    + args[7].dat->size * ( range[0] * 1 - args[7].dat->offset[0] ) ];

    p_a[8] = &args[8].data[
    + args[8].dat->size * args[8].dat->block_size[0] * ( start * 1 - args[8].dat->offset[1] )
    + args[8].dat->size * ( range[0] * 1 - args[8].dat->offset[0] ) ];

    p_a[9] = &args[9].data[
    + args[9].dat->size * args[9].dat->block_size[0] * ( start * 1 - args[9].dat->offset[1] )
    + args[9].dat->size * ( range[0] * 1 - args[9].dat->offset[0] ) ];

    p_a[10] = &args[10].data[
    + args[10].dat->size * args[10].dat->block_size[0] * ( start * 1 - args[10].dat->offset[1] )
    + args[10].dat->size * ( range[0] * 1 - args[10].dat->offset[0] ) ];

    p_a[11] = &args[11].data[
    + args[11].dat->size * args[11].dat->block_size[0] * ( start * 1 - args[11].dat->offset[1] )
    + args[11].dat->size * ( range[0] * 1 - args[11].dat->offset[0] ) ];

    p_a[12] = &args[12].data[
    + args[12].dat->size * args[12].dat->block_size[0] * ( start * 1 - args[12].dat->offset[1] )
    + args[12].dat->size * ( range[0] * 1 - args[12].dat->offset[0] ) ];

    p_a[13] = &args[13].data[
    + args[13].dat->size * args[13].dat->block_size[0] * ( start * 1 - args[13].dat->offset[1] )
    + args[13].dat->size * ( range[0] * 1 - args[13].dat->offset[0] ) ];


    for ( int n_y=start; n_y<finish; n_y++ ){
      for ( int n_x=range[0]; n_x<range[0]+(range[1]-range[0])/4; n_x++ ){
        //call kernel function, passing in pointers to data - vectorised
        #pragma simd
        for ( int i=0; i<4; i++ ){
          PdV_kernel_nopredict(  (double *)p_a[0]+ i*1, (double *)p_a[1]+ i*1,
           (double *)p_a[2]+ i*1, (double *)p_a[3]+ i*1,
           (double *)p_a[4]+ i*1, (double *)p_a[5]+ i*1,
           (double *)p_a[6]+ i*1, (double *)p_a[7]+ i*1,
           (double *)p_a[8]+ i*1, (double *)p_a[9]+ i*1,
           (double *)p_a[10]+ i*1, (double *)p_a[11]+ i*1,
           (double *)p_a[12]+ i*1, (double *)p_a[13]+ i*1 );

        }

        //shift pointers to data x direction
        p_a[0]= p_a[0] + (dat0 * off0_1)*4;
        p_a[1]= p_a[1] + (dat1 * off1_1)*4;
        p_a[2]= p_a[2] + (dat2 * off2_1)*4;
        p_a[3]= p_a[3] + (dat3 * off3_1)*4;
        p_a[4]= p_a[4] + (dat4 * off4_1)*4;
        p_a[5]= p_a[5] + (dat5 * off5_1)*4;
        p_a[6]= p_a[6] + (dat6 * off6_1)*4;
        p_a[7]= p_a[7] + (dat7 * off7_1)*4;
        p_a[8]= p_a[8] + (dat8 * off8_1)*4;
        p_a[9]= p_a[9] + (dat9 * off9_1)*4;
        p_a[10]= p_a[10] + (dat10 * off10_1)*4;
        p_a[11]= p_a[11] + (dat11 * off11_1)*4;
        p_a[12]= p_a[12] + (dat12 * off12_1)*4;
        p_a[13]= p_a[13] + (dat13 * off13_1)*4;
      }

      for ( int n_x=range[0]+((range[1]-range[0])/4)*4; n_x<range[1]; n_x++ ){
        //call kernel function, passing in pointers to data - remainder
        PdV_kernel_nopredict(  (double *)p_a[0], (double *)p_a[1],
           (double *)p_a[2], (double *)p_a[3],
           (double *)p_a[4], (double *)p_a[5],
           (double *)p_a[6], (double *)p_a[7],
           (double *)p_a[8], (double *)p_a[9],
           (double *)p_a[10], (double *)p_a[11],
           (double *)p_a[12], (double *)p_a[13] );


        //shift pointers to data x direction
        p_a[0]= p_a[0] + (dat0 * off0_1);
        p_a[1]= p_a[1] + (dat1 * off1_1);
        p_a[2]= p_a[2] + (dat2 * off2_1);
        p_a[3]= p_a[3] + (dat3 * off3_1);
        p_a[4]= p_a[4] + (dat4 * off4_1);
        p_a[5]= p_a[5] + (dat5 * off5_1);
        p_a[6]= p_a[6] + (dat6 * off6_1);
        p_a[7]= p_a[7] + (dat7 * off7_1);
        p_a[8]= p_a[8] + (dat8 * off8_1);
        p_a[9]= p_a[9] + (dat9 * off9_1);
        p_a[10]= p_a[10] + (dat10 * off10_1);
        p_a[11]= p_a[11] + (dat11 * off11_1);
        p_a[12]= p_a[12] + (dat12 * off12_1);
        p_a[13]= p_a[13] + (dat13 * off13_1);
      }

      //shift pointers to data y direction
      p_a[0]= p_a[0] + (dat0 * off0_2);
      p_a[1]= p_a[1] + (dat1 * off1_2);
      p_a[2]= p_a[2] + (dat2 * off2_2);
      p_a[3]= p_a[3] + (dat3 * off3_2);
      p_a[4]= p_a[4] + (dat4 * off4_2);
      p_a[5]= p_a[5] + (dat5 * off5_2);
      p_a[6]= p_a[6] + (dat6 * off6_2);
      p_a[7]= p_a[7] + (dat7 * off7_2);
      p_a[8]= p_a[8] + (dat8 * off8_2);
      p_a[9]= p_a[9] + (dat9 * off9_2);
      p_a[10]= p_a[10] + (dat10 * off10_2);
      p_a[11]= p_a[11] + (dat11 * off11_2);
      p_a[12]= p_a[12] + (dat12 * off12_2);
      p_a[13]= p_a[13] + (dat13 * off13_2);
    }
  }

  ops_set_dirtybit(args, 14);


  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[81].count++;
  OPS_kernels[81].time += t2-t1;
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg5);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg6);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg7);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg8);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg9);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg10);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg11);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg12);
  OPS_kernels[81].transfer += ops_compute_transfer(dim, range, &arg13);
}
