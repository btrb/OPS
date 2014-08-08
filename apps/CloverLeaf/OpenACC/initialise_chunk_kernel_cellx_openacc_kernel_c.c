//
// auto-generated by ops.py on 2014-08-08 12:31
//

#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_initialise_chunk_kernel_cellx;
int xdim1_initialise_chunk_kernel_cellx;
int xdim2_initialise_chunk_kernel_cellx;

#define OPS_ACC0(x,y) (x+xdim0_initialise_chunk_kernel_cellx*(y))
#define OPS_ACC1(x,y) (x+xdim1_initialise_chunk_kernel_cellx*(y))
#define OPS_ACC2(x,y) (x+xdim2_initialise_chunk_kernel_cellx*(y))

//user function
inline 
void initialise_chunk_kernel_cellx(const double *vertexx, double* cellx, double *celldx) {

  int x_min=field.x_min-2;
  int x_max=field.x_max-2;
  int y_min=field.y_min-2;
  int y_max=field.y_max-2;

  double min_x, min_y, d_x, d_y;

  d_x = (grid.xmax - grid.xmin)/(double)grid.x_cells;
  d_y = (grid.ymax - grid.ymin)/(double)grid.y_cells;

  min_x=grid.xmin+d_x;
  min_y=grid.ymin+d_y;

  cellx[OPS_ACC1(0,0)]  = 0.5*( vertexx[OPS_ACC0(0,0)] + vertexx[OPS_ACC0(1,0)] );
  celldx[OPS_ACC2(0,0)]  = d_x;

}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2


void initialise_chunk_kernel_cellx_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      initialise_chunk_kernel_cellx(  p_a0 + n_x*1 + n_y*xdim0_initialise_chunk_kernel_cellx*0,
           p_a1 + n_x*1 + n_y*xdim1_initialise_chunk_kernel_cellx*0, p_a2 + n_x*1 + n_y*xdim2_initialise_chunk_kernel_cellx*0 );

    }
  }
}
