//
// auto-generated by ops.py on 2013-11-28 10:24
//

#include "lib.h"
//user function
#include "initialise_chunk_kernel.h"

// host stub function
void ops_par_loop_initialise_chunk_kernel_celly(char const *name, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {

  char *p_a[3];
  int  offs[3][2];
  ops_arg args[3] = { arg0, arg1, arg2};


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

  int off0_1 = offs[0][0];
  int off0_2 = offs[0][1];
  int dat0 = args[0].dat->size;
  int off1_1 = offs[1][0];
  int off1_2 = offs[1][1];
  int dat1 = args[1].dat->size;
  int off2_1 = offs[2][0];
  int off2_2 = offs[2][1];
  int dat2 = args[2].dat->size;

  //set up initial pointers
  p_a[0] = &args[0].data[
  + args[0].dat->size * args[0].dat->block_size[0] * ( range[2] * 1 - args[0].dat->offset[1] )
  + args[0].dat->size * ( range[0] * 1 - args[0].dat->offset[0] ) ];

  p_a[1] = &args[1].data[
  + args[1].dat->size * args[1].dat->block_size[0] * ( range[2] * 1 - args[1].dat->offset[1] )
  + args[1].dat->size * ( range[0] * 1 - args[1].dat->offset[0] ) ];

  p_a[2] = &args[2].data[
  + args[2].dat->size * args[2].dat->block_size[0] * ( range[2] * 1 - args[2].dat->offset[1] )
  + args[2].dat->size * ( range[0] * 1 - args[2].dat->offset[0] ) ];


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(85,"initialise_chunk_kernel_celly");
  ops_timers_core(&c1,&t1);

  ops_halo_exchanges(args, 3);

  xdim0 = args[0].dat->block_size[0];
  xdim1 = args[1].dat->block_size[0];
  xdim2 = args[2].dat->block_size[0];

  for ( int n_y=range[2]; n_y<range[3]; n_y++ ){
    for ( int n_x=range[0]; n_x<range[0]+(range[1]-range[0])/4; n_x++ ){
      //call kernel function, passing in pointers to data -vectorised
      #pragma simd
      for ( int i=0; i<4; i++ ){
        initialise_chunk_kernel_celly(  (double *)p_a[0]+ i*1, (double *)p_a[1]+ i*1, (double *)p_a[2]+ i*1 );

      }

      //shift pointers to data x direction
      p_a[0]= p_a[0] + (dat0 * off0_1)*4;
      p_a[1]= p_a[1] + (dat1 * off1_1)*4;
      p_a[2]= p_a[2] + (dat2 * off2_1)*4;
    }

    for ( int n_x=range[0]+((range[1]-range[0])/4)*4; n_x<range[1]; n_x++ ){
      //call kernel function, passing in pointers to data - remainder
      initialise_chunk_kernel_celly(  (double *)p_a[0], (double *)p_a[1], (double *)p_a[2] );


      //shift pointers to data x direction
      p_a[0]= p_a[0] + (dat0 * off0_1);
      p_a[1]= p_a[1] + (dat1 * off1_1);
      p_a[2]= p_a[2] + (dat2 * off2_1);
    }

    //shift pointers to data y direction
    p_a[0]= p_a[0] + (dat0 * off0_2);
    p_a[1]= p_a[1] + (dat1 * off1_2);
    p_a[2]= p_a[2] + (dat2 * off2_2);
  }
  ops_set_dirtybit(args, 3);


  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[85].count++;
  OPS_kernels[85].time += t2-t1;
  OPS_kernels[85].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[85].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[85].transfer += ops_compute_transfer(dim, range, &arg2);
}
