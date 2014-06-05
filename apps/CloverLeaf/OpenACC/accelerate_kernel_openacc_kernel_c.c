//
<<<<<<< HEAD
// auto-generated by ops.py on 2014-06-17 17:28
=======
// auto-generated by ops.py on 2014-06-05 12:26
>>>>>>> 6ba9c42... OpenCL broken after rebase
//

#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_accelerate_kernel;
int xdim1_accelerate_kernel;
int xdim2_accelerate_kernel;
int xdim3_accelerate_kernel;
int xdim4_accelerate_kernel;
int xdim5_accelerate_kernel;
int xdim6_accelerate_kernel;
int xdim7_accelerate_kernel;
int xdim8_accelerate_kernel;
int xdim9_accelerate_kernel;
int xdim10_accelerate_kernel;

#define OPS_ACC0(x,y) (x+xdim0_accelerate_kernel*(y))
#define OPS_ACC1(x,y) (x+xdim1_accelerate_kernel*(y))
#define OPS_ACC2(x,y) (x+xdim2_accelerate_kernel*(y))
#define OPS_ACC3(x,y) (x+xdim3_accelerate_kernel*(y))
#define OPS_ACC4(x,y) (x+xdim4_accelerate_kernel*(y))
#define OPS_ACC5(x,y) (x+xdim5_accelerate_kernel*(y))
#define OPS_ACC6(x,y) (x+xdim6_accelerate_kernel*(y))
#define OPS_ACC7(x,y) (x+xdim7_accelerate_kernel*(y))
#define OPS_ACC8(x,y) (x+xdim8_accelerate_kernel*(y))
#define OPS_ACC9(x,y) (x+xdim9_accelerate_kernel*(y))
#define OPS_ACC10(x,y) (x+xdim10_accelerate_kernel*(y))

//user function
inline 
void accelerate_kernel( const double *density0, const double *volume,
                double *stepbymass, const double *xvel0, double *xvel1,
                const double *xarea, const double *pressure,
                const double *yvel0, double *yvel1,
                const double *yarea, const double *viscosity) {

  double nodal_mass;

  nodal_mass = ( density0[OPS_ACC0(-1,-1)] * volume[OPS_ACC1(-1,-1)]
    + density0[OPS_ACC0(0,-1)] * volume[OPS_ACC1(0,-1)]
    + density0[OPS_ACC0(0,0)] * volume[OPS_ACC1(0,0)]
    + density0[OPS_ACC0(-1,0)] * volume[OPS_ACC1(-1,0)] ) * 0.25;

  stepbymass[OPS_ACC2(0,0)] = 0.5*dt/ nodal_mass;



  xvel1[OPS_ACC4(0,0)] = xvel0[OPS_ACC3(0,0)] - stepbymass[OPS_ACC2(0,0)] *
            ( xarea[OPS_ACC5(0,0)]  * ( pressure[OPS_ACC6(0,0)] - pressure[OPS_ACC6(-1,0)] ) +
              xarea[OPS_ACC5(0,-1)] * ( pressure[OPS_ACC6(0,-1)] - pressure[OPS_ACC6(-1,-1)] ) );



  yvel1[OPS_ACC8(0,0)] = yvel0[OPS_ACC7(0,0)] - stepbymass[OPS_ACC2(0,0)] *
            ( yarea[OPS_ACC9(0,0)]  * ( pressure[OPS_ACC6(0,0)] - pressure[OPS_ACC6(0,-1)] ) +
              yarea[OPS_ACC9(-1,0)] * ( pressure[OPS_ACC6(-1,0)] - pressure[OPS_ACC6(-1,-1)] ) );



  xvel1[OPS_ACC4(0,0)] = xvel1[OPS_ACC4(0,0)] - stepbymass[OPS_ACC2(0,0)] *
            ( xarea[OPS_ACC5(0,0)] * ( viscosity[OPS_ACC10(0,0)] - viscosity[OPS_ACC10(-1,0)] ) +
              xarea[OPS_ACC5(0,-1)] * ( viscosity[OPS_ACC10(0,-1)] - viscosity[OPS_ACC10(-1,-1)] ) );



  yvel1[OPS_ACC8(0,0)] = yvel1[OPS_ACC8(0,0)] - stepbymass[OPS_ACC2(0,0)] *
            ( yarea[OPS_ACC9(0,0)] * ( viscosity[OPS_ACC10(0,0)] - viscosity[OPS_ACC10(0,-1)] ) +
              yarea[OPS_ACC9(-1,0)] * ( viscosity[OPS_ACC10(-1,0)] - viscosity[OPS_ACC10(-1,-1)] ) );

}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10


void accelerate_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7,p_a8,p_a9,p_a10)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      accelerate_kernel(  p_a0 + n_x*1 + n_y*xdim0_accelerate_kernel*1,
           p_a1 + n_x*1 + n_y*xdim1_accelerate_kernel*1, p_a2 + n_x*1 + n_y*xdim2_accelerate_kernel*1,
           p_a3 + n_x*1 + n_y*xdim3_accelerate_kernel*1, p_a4 + n_x*1 + n_y*xdim4_accelerate_kernel*1,
           p_a5 + n_x*1 + n_y*xdim5_accelerate_kernel*1, p_a6 + n_x*1 + n_y*xdim6_accelerate_kernel*1,
           p_a7 + n_x*1 + n_y*xdim7_accelerate_kernel*1, p_a8 + n_x*1 + n_y*xdim8_accelerate_kernel*1,
           p_a9 + n_x*1 + n_y*xdim9_accelerate_kernel*1, p_a10 + n_x*1 + n_y*xdim10_accelerate_kernel*1 );

    }
  }
}
