//
// auto-generated by ops.py on 2014-03-17 15:34
//



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_generate_chunk_kernel(char const *, ops_block, int , int*,
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

//#include "generate_chunk_kernel.h"

void generate()
{

  int x_cells = grid->x_cells;
  int y_cells = grid->y_cells;
  int x_min = field->x_min;
  int x_max = field->x_max;
  int y_min = field->y_min;
  int y_max = field->y_max;

  int rangexy[] = {x_min-2,x_max+2,y_min-2,y_max+2};

  ops_par_loop_generate_chunk_kernel("generate_chunk_kernel", clover_grid, 2, rangexy,
               ops_arg_dat(vertexx, S2D_00_P10_STRID2D_X, "double", OPS_READ),
               ops_arg_dat(vertexy, S2D_00_0P1_STRID2D_Y, "double", OPS_READ),
               ops_arg_dat(energy0, S2D_00, "double", OPS_WRITE),
               ops_arg_dat(density0, S2D_00, "double", OPS_WRITE),
               ops_arg_dat(xvel0, S2D_00_P10_0P1_P1P1, "double", OPS_WRITE),
               ops_arg_dat(yvel0, S2D_00_P10_0P1_P1P1, "double", OPS_WRITE),
               ops_arg_dat(cellx, S2D_00_P10_STRID2D_X, "double", OPS_READ),
               ops_arg_dat(celly, S2D_00_0P1_STRID2D_Y, "double", OPS_READ));


}
