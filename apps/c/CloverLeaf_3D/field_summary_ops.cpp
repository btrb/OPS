//
// auto-generated by ops.py
//


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define OPS_3D
#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_field_summary_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );



#include "data.h"
#include "definitions.h"

//#include "field_summary_kernel.h"

void ideal_gas(int predict);

void field_summary()
{

  int x_min = field.x_min;
  int x_max = field.x_max;
  int y_min = field.y_min;
  int y_max = field.y_max;
  int z_min = field.z_min;
  int z_max = field.z_max;

  int rangexyz_inner[] = {x_min,x_max,y_min,y_max,z_min,z_max};

  ideal_gas(FALSE);

  ops_par_loop_field_summary_kernel("field_summary_kernel", clover_grid, 3, rangexyz_inner,
               ops_arg_dat(volume, 1, S3D_000, "double", OPS_READ),
               ops_arg_dat(density0, 1, S3D_000, "double", OPS_READ),
               ops_arg_dat(energy0, 1, S3D_000, "double", OPS_READ),
               ops_arg_dat(pressure, 1, S3D_000, "double", OPS_READ),
               ops_arg_dat(xvel0, 1, S3D_000_fP1P1P1, "double", OPS_READ),
               ops_arg_dat(yvel0, 1, S3D_000_fP1P1P1, "double", OPS_READ),
               ops_arg_dat(zvel0, 1, S3D_000_fP1P1P1, "double", OPS_READ),
               ops_arg_reduce(red_vol, 1, "double", OPS_INC),
               ops_arg_reduce(red_mass, 1, "double", OPS_INC),
               ops_arg_reduce(red_ie, 1, "double", OPS_INC),
               ops_arg_reduce(red_ke, 1, "double", OPS_INC),
               ops_arg_reduce(red_press, 1, "double", OPS_INC));
}

void field_summary_report(int step) {
  double qa_diff;
  double vol= 0.0 , mass = 0.0, ie = 0.0, ke = 0.0, press = 0.0;

   ops_reduction_result(red_vol,&vol);
   ops_reduction_result(red_mass,&mass);
   ops_reduction_result(red_ie,&ie);
   ops_reduction_result(red_ke,&ke);
   ops_reduction_result(red_press,&press);

  ops_fprintf(g_out,"\n");
  ops_fprintf(g_out,"\n Time %lf\n",clover_time);
  ops_fprintf(g_out,"              %-10s  %-10s  %-10s  %-10s  %-15s  %-15s  %-s\n",
  " Volume"," Mass"," Density"," Pressure"," Internal Energy","Kinetic Energy","Total Energy");
  ops_fprintf(g_out," step:   %3d   %-10.3E  %-10.3E  %-10.3E  %-10.3E  %-15.3E  %-15.3E  %-.3E",
          step, vol, mass, mass/vol, press/vol, ie, ke, ie+ke);

  if(complete == TRUE && test_problem) {
    qa_diff = DBL_MAX;
    if(test_problem == 1) qa_diff=fabs((100.0*(ke/3.64560737191257))-100.0);
    if(test_problem == 2) qa_diff=fabs((100.0*(ke/20.0546870878964))-100.0);
    if(test_problem == 3) qa_diff=fabs((100.0*(ke/0.37517221925665))-100.0);
    if(test_problem == 4) qa_diff=fabs((100.0*(ke/17.9845165368889))-100.0);
    if(test_problem == 5) qa_diff=fabs((100.0*(ke/2.05018938455107))-100.0);

    ops_printf("\n\nTest problem %d is within %3.15E %% of the expected solution\n",test_problem, qa_diff);
    ops_fprintf(g_out,"\n\nTest problem %d is within %3.15E %% of the expected solution\n",test_problem, qa_diff);

    if(qa_diff < 0.001) {
      ops_printf("This test is considered PASSED\n");
      ops_fprintf(g_out,"This test is considered PASSED\n");
    }
    else {
      ops_printf("This test is considered FAILED\n");
      ops_fprintf(g_out,"This test is considered FAILED\n");
    }
  }
  fflush(g_out);

}
