//
// auto-generated by ops.py on 2014-08-08 13:40
//

#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_advec_cell_kernel4_xdir;
int ydim0_advec_cell_kernel4_xdir;
int xdim1_advec_cell_kernel4_xdir;
int ydim1_advec_cell_kernel4_xdir;
int xdim2_advec_cell_kernel4_xdir;
int ydim2_advec_cell_kernel4_xdir;
int xdim3_advec_cell_kernel4_xdir;
int ydim3_advec_cell_kernel4_xdir;
int xdim4_advec_cell_kernel4_xdir;
int ydim4_advec_cell_kernel4_xdir;
int xdim5_advec_cell_kernel4_xdir;
int ydim5_advec_cell_kernel4_xdir;
int xdim6_advec_cell_kernel4_xdir;
int ydim6_advec_cell_kernel4_xdir;
int xdim7_advec_cell_kernel4_xdir;
int ydim7_advec_cell_kernel4_xdir;
int xdim8_advec_cell_kernel4_xdir;
int ydim8_advec_cell_kernel4_xdir;
int xdim9_advec_cell_kernel4_xdir;
int ydim9_advec_cell_kernel4_xdir;
int xdim10_advec_cell_kernel4_xdir;
int ydim10_advec_cell_kernel4_xdir;

#define OPS_ACC0(x,y,z) (x+xdim0_advec_cell_kernel4_xdir*(y)+xdim0_advec_cell_kernel4_xdir*ydim0_advec_cell_kernel4_xdir*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_advec_cell_kernel4_xdir*(y)+xdim1_advec_cell_kernel4_xdir*ydim1_advec_cell_kernel4_xdir*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_advec_cell_kernel4_xdir*(y)+xdim2_advec_cell_kernel4_xdir*ydim2_advec_cell_kernel4_xdir*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_advec_cell_kernel4_xdir*(y)+xdim3_advec_cell_kernel4_xdir*ydim3_advec_cell_kernel4_xdir*(z))
#define OPS_ACC4(x,y,z) (x+xdim4_advec_cell_kernel4_xdir*(y)+xdim4_advec_cell_kernel4_xdir*ydim4_advec_cell_kernel4_xdir*(z))
#define OPS_ACC5(x,y,z) (x+xdim5_advec_cell_kernel4_xdir*(y)+xdim5_advec_cell_kernel4_xdir*ydim5_advec_cell_kernel4_xdir*(z))
#define OPS_ACC6(x,y,z) (x+xdim6_advec_cell_kernel4_xdir*(y)+xdim6_advec_cell_kernel4_xdir*ydim6_advec_cell_kernel4_xdir*(z))
#define OPS_ACC7(x,y,z) (x+xdim7_advec_cell_kernel4_xdir*(y)+xdim7_advec_cell_kernel4_xdir*ydim7_advec_cell_kernel4_xdir*(z))
#define OPS_ACC8(x,y,z) (x+xdim8_advec_cell_kernel4_xdir*(y)+xdim8_advec_cell_kernel4_xdir*ydim8_advec_cell_kernel4_xdir*(z))
#define OPS_ACC9(x,y,z) (x+xdim9_advec_cell_kernel4_xdir*(y)+xdim9_advec_cell_kernel4_xdir*ydim9_advec_cell_kernel4_xdir*(z))
#define OPS_ACC10(x,y,z) (x+xdim10_advec_cell_kernel4_xdir*(y)+xdim10_advec_cell_kernel4_xdir*ydim10_advec_cell_kernel4_xdir*(z))

//user function

inline void advec_cell_kernel4_xdir( double *density1, double *energy1,
                         const double *mass_flux_x, const double *vol_flux_x,
                         const double *pre_vol, const double *post_vol,
                         double *pre_mass, double *post_mass,
                         double *advec_vol, double *post_ener,
                         const double *ener_flux) {

  pre_mass[OPS_ACC6(0,0,0)] = density1[OPS_ACC0(0,0,0)] * pre_vol[OPS_ACC4(0,0,0)];
  post_mass[OPS_ACC7(0,0,0)] = pre_mass[OPS_ACC6(0,0,0)] + mass_flux_x[OPS_ACC2(0,0,0)] - mass_flux_x[OPS_ACC2(1,0,0)];
  post_ener[OPS_ACC9(0,0,0)] = ( energy1[OPS_ACC1(0,0,0)] * pre_mass[OPS_ACC6(0,0,0)] + ener_flux[OPS_ACC10(0,0,0)] - ener_flux[OPS_ACC10(1,0,0)])/post_mass[OPS_ACC7(0,0,0)];
  advec_vol[OPS_ACC8(0,0,0)] = pre_vol[OPS_ACC4(0,0,0)] + vol_flux_x[OPS_ACC3(0,0,0)] - vol_flux_x[OPS_ACC3(1,0,0)];
  density1[OPS_ACC0(0,0,0)] = post_mass[OPS_ACC7(0,0,0)]/advec_vol[OPS_ACC8(0,0,0)];
  energy1[OPS_ACC1(0,0,0)] = post_ener[OPS_ACC9(0,0,0)];

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


void advec_cell_kernel4_xdir_c_wrapper(
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
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7,p_a8,p_a9,p_a10)
  #pragma acc loop
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        advec_cell_kernel4_xdir(  p_a0 + n_x*1 + n_y*xdim0_advec_cell_kernel4_xdir*1 + n_z*xdim0_advec_cell_kernel4_xdir*ydim0_advec_cell_kernel4_xdir*1,
           p_a1 + n_x*1 + n_y*xdim1_advec_cell_kernel4_xdir*1 + n_z*xdim1_advec_cell_kernel4_xdir*ydim1_advec_cell_kernel4_xdir*1,
           p_a2 + n_x*1 + n_y*xdim2_advec_cell_kernel4_xdir*1 + n_z*xdim2_advec_cell_kernel4_xdir*ydim2_advec_cell_kernel4_xdir*1,
           p_a3 + n_x*1 + n_y*xdim3_advec_cell_kernel4_xdir*1 + n_z*xdim3_advec_cell_kernel4_xdir*ydim3_advec_cell_kernel4_xdir*1,
           p_a4 + n_x*1 + n_y*xdim4_advec_cell_kernel4_xdir*1 + n_z*xdim4_advec_cell_kernel4_xdir*ydim4_advec_cell_kernel4_xdir*1,
           p_a5 + n_x*1 + n_y*xdim5_advec_cell_kernel4_xdir*1 + n_z*xdim5_advec_cell_kernel4_xdir*ydim5_advec_cell_kernel4_xdir*1,
           p_a6 + n_x*1 + n_y*xdim6_advec_cell_kernel4_xdir*1 + n_z*xdim6_advec_cell_kernel4_xdir*ydim6_advec_cell_kernel4_xdir*1,
           p_a7 + n_x*1 + n_y*xdim7_advec_cell_kernel4_xdir*1 + n_z*xdim7_advec_cell_kernel4_xdir*ydim7_advec_cell_kernel4_xdir*1,
           p_a8 + n_x*1 + n_y*xdim8_advec_cell_kernel4_xdir*1 + n_z*xdim8_advec_cell_kernel4_xdir*ydim8_advec_cell_kernel4_xdir*1,
           p_a9 + n_x*1 + n_y*xdim9_advec_cell_kernel4_xdir*1 + n_z*xdim9_advec_cell_kernel4_xdir*ydim9_advec_cell_kernel4_xdir*1,
           p_a10 + n_x*1 + n_y*xdim10_advec_cell_kernel4_xdir*1 + n_z*xdim10_advec_cell_kernel4_xdir*ydim10_advec_cell_kernel4_xdir*1 );

      }
    }
  }
}
