//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_advec_mom_kernel_z3;
int ydim0_advec_mom_kernel_z3;
int xdim1_advec_mom_kernel_z3;
int ydim1_advec_mom_kernel_z3;
int xdim2_advec_mom_kernel_z3;
int ydim2_advec_mom_kernel_z3;
int xdim3_advec_mom_kernel_z3;
int ydim3_advec_mom_kernel_z3;


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3


#define OPS_ACC0(x,y,z) (x+xdim0_advec_mom_kernel_z3*(y)+xdim0_advec_mom_kernel_z3*ydim0_advec_mom_kernel_z3*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_advec_mom_kernel_z3*(y)+xdim1_advec_mom_kernel_z3*ydim1_advec_mom_kernel_z3*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_advec_mom_kernel_z3*(y)+xdim2_advec_mom_kernel_z3*ydim2_advec_mom_kernel_z3*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_advec_mom_kernel_z3*(y)+xdim3_advec_mom_kernel_z3*ydim3_advec_mom_kernel_z3*(z))

//user function

inline void advec_mom_kernel_z3( double *pre_vol, double *post_vol,
                          const double *volume,
                          const double *vol_flux_z) {

  post_vol[OPS_ACC1(0,0,0)]  = volume[OPS_ACC2(0,0,0)];
  pre_vol[OPS_ACC0(0,0,0)]   = post_vol[OPS_ACC1(0,0,0)]  + vol_flux_z[OPS_ACC3(0,0,1)] - vol_flux_z[OPS_ACC3(0,0,0)];

}


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3



void advec_mom_kernel_z3_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3)
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
        advec_mom_kernel_z3(  p_a0 + n_x*1*1 + n_y*xdim0_advec_mom_kernel_z3*1*1 + n_z*xdim0_advec_mom_kernel_z3*ydim0_advec_mom_kernel_z3*1*1,
           p_a1 + n_x*1*1 + n_y*xdim1_advec_mom_kernel_z3*1*1 + n_z*xdim1_advec_mom_kernel_z3*ydim1_advec_mom_kernel_z3*1*1,
           p_a2 + n_x*1*1 + n_y*xdim2_advec_mom_kernel_z3*1*1 + n_z*xdim2_advec_mom_kernel_z3*ydim2_advec_mom_kernel_z3*1*1,
           p_a3 + n_x*1*1 + n_y*xdim3_advec_mom_kernel_z3*1*1 + n_z*xdim3_advec_mom_kernel_z3*ydim3_advec_mom_kernel_z3*1*1 );

      }
    }
  }
}
