//
// auto-generated by ops.py on 2013-11-28 10:55
//



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_advec_cell_kernel1_xdir(char const *, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel2_xdir(char const *, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel3_xdir(char const *, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel4_xdir(char const *, int , int*,
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

void ops_par_loop_advec_cell_kernel1_ydir(char const *, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel2_ydir(char const *, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel3_ydir(char const *, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_cell_kernel4_ydir(char const *, int , int*,
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
//#include "advec_cell_kernel.h"

void advec_cell(int sweep_number, int dir)
{

  int x_cells = grid->x_cells;
  int y_cells = grid->y_cells;
  int x_min = field->x_min;
  int x_max = field->x_max;
  int y_min = field->y_min;
  int y_max = field->y_max;

  int rangexy[] = {x_min-2,x_max+2,y_min-2,y_max+2};
  int rangexy_inner[] = {x_min,x_max,y_min,y_max};

  int rangexy_inner_plus2x[] = {x_min,x_max+2,y_min,y_max};
  int rangexy_inner_plus2y[] = {x_min,x_max,y_min,y_max+2};


  if(dir == g_xdir) {

    if(sweep_number == 1) {
      ops_par_loop_advec_cell_kernel1_xdir("advec_cell_kernel1_xdir", 2, rangexy,
                   ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(work_array2, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                   ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ),
                   ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ));
    }
    else {
      ops_par_loop_advec_cell_kernel2_xdir("advec_cell_kernel2_xdir", 2, rangexy,
                   ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(work_array2, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                   ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ));
    }

    ops_par_loop_advec_cell_kernel3_xdir("advec_cell_kernel3_xdir", 2, rangexy_inner_plus2x,
                 ops_arg_dat(vol_flux_x, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array1, S2D_00_P10_M10_M20, "double", OPS_READ),
                 ops_arg_dat(xx, s2D_00_P10_STRID2D_X, "int", OPS_READ),
                 ops_arg_dat(vertexdx, S2D_00_P10_M10_M20_STRID2D_X, "double", OPS_READ),
                 ops_arg_dat(density1, S2D_00_P10_M10_M20, "double", OPS_READ),
                 ops_arg_dat(energy1, S2D_00_P10_M10_M20, "double", OPS_READ),
                 ops_arg_dat(mass_flux_x, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00, "double", OPS_WRITE));

    ops_par_loop_advec_cell_kernel4_xdir("advec_cell_kernel4_xdir", 2, rangexy_inner,
                 ops_arg_dat(density1, S2D_00, "double", OPS_RW),
                 ops_arg_dat(energy1, S2D_00, "double", OPS_RW),
                 ops_arg_dat(mass_flux_x, S2D_00_P10, "double", OPS_READ),
                 ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ),
                 ops_arg_dat(work_array1, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array2, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array3, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array4, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array5, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array6, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00_P10, "double", OPS_WRITE));

  }
  else {


    if(sweep_number == 1) {
      ops_par_loop_advec_cell_kernel1_ydir("advec_cell_kernel1_ydir", 2, rangexy,
                   ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(work_array2, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                   ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ),
                   ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ));
    }
    else {

      ops_par_loop_advec_cell_kernel2_ydir("advec_cell_kernel2_ydir", 2, rangexy,
                   ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(work_array2, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                   ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ));

  }

    ops_par_loop_advec_cell_kernel3_ydir("advec_cell_kernel3_ydir", 2, rangexy_inner_plus2y,
                 ops_arg_dat(vol_flux_y, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array1, S2D_00_0P1_0M1_0M2, "double", OPS_READ),
                 ops_arg_dat(yy, S2D_00_0P1_STRID2D_Y, "int", OPS_READ),
                 ops_arg_dat(vertexdy, S2D_00_0P1_0M1_0M2_STRID2D_Y, "double", OPS_READ),
                 ops_arg_dat(density1, S2D_00_0P1_0M1_0M2, "double", OPS_READ),
                 ops_arg_dat(energy1, S2D_00_0P1_0M1_0M2, "double", OPS_READ),
                 ops_arg_dat(mass_flux_y, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00, "double", OPS_WRITE));

    ops_par_loop_advec_cell_kernel4_ydir("advec_cell_kernel4_ydir", 2, rangexy_inner,
                 ops_arg_dat(density1, S2D_00, "double", OPS_RW),
                 ops_arg_dat(energy1, S2D_00, "double", OPS_RW),
                 ops_arg_dat(mass_flux_y, S2D_00_0P1, "double", OPS_READ),
                 ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ),
                 ops_arg_dat(work_array1, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array2, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array3, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array4, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array5, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array6, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00_0P1, "double", OPS_WRITE));

  }

}
