//
// auto-generated by ops.py
//

int xdim0_PdV_kernel_predict;
int ydim0_PdV_kernel_predict;
int xdim1_PdV_kernel_predict;
int ydim1_PdV_kernel_predict;
int xdim2_PdV_kernel_predict;
int ydim2_PdV_kernel_predict;
int xdim3_PdV_kernel_predict;
int ydim3_PdV_kernel_predict;
int xdim4_PdV_kernel_predict;
int ydim4_PdV_kernel_predict;
int xdim5_PdV_kernel_predict;
int ydim5_PdV_kernel_predict;
int xdim6_PdV_kernel_predict;
int ydim6_PdV_kernel_predict;
int xdim7_PdV_kernel_predict;
int ydim7_PdV_kernel_predict;
int xdim8_PdV_kernel_predict;
int ydim8_PdV_kernel_predict;
int xdim9_PdV_kernel_predict;
int ydim9_PdV_kernel_predict;
int xdim10_PdV_kernel_predict;
int ydim10_PdV_kernel_predict;
int xdim11_PdV_kernel_predict;
int ydim11_PdV_kernel_predict;
int xdim12_PdV_kernel_predict;
int ydim12_PdV_kernel_predict;
int xdim13_PdV_kernel_predict;
int ydim13_PdV_kernel_predict;


#define OPS_ACC0(x,y,z) (n_x*1+n_y*xdim0_PdV_kernel_predict*1+n_z*xdim0_PdV_kernel_predict*ydim0_PdV_kernel_predict*1+x+xdim0_PdV_kernel_predict*(y)+xdim0_PdV_kernel_predict*ydim0_PdV_kernel_predict*(z))
#define OPS_ACC1(x,y,z) (n_x*1+n_y*xdim1_PdV_kernel_predict*1+n_z*xdim1_PdV_kernel_predict*ydim1_PdV_kernel_predict*1+x+xdim1_PdV_kernel_predict*(y)+xdim1_PdV_kernel_predict*ydim1_PdV_kernel_predict*(z))
#define OPS_ACC2(x,y,z) (n_x*1+n_y*xdim2_PdV_kernel_predict*1+n_z*xdim2_PdV_kernel_predict*ydim2_PdV_kernel_predict*1+x+xdim2_PdV_kernel_predict*(y)+xdim2_PdV_kernel_predict*ydim2_PdV_kernel_predict*(z))
#define OPS_ACC3(x,y,z) (n_x*1+n_y*xdim3_PdV_kernel_predict*1+n_z*xdim3_PdV_kernel_predict*ydim3_PdV_kernel_predict*1+x+xdim3_PdV_kernel_predict*(y)+xdim3_PdV_kernel_predict*ydim3_PdV_kernel_predict*(z))
#define OPS_ACC4(x,y,z) (n_x*1+n_y*xdim4_PdV_kernel_predict*1+n_z*xdim4_PdV_kernel_predict*ydim4_PdV_kernel_predict*1+x+xdim4_PdV_kernel_predict*(y)+xdim4_PdV_kernel_predict*ydim4_PdV_kernel_predict*(z))
#define OPS_ACC5(x,y,z) (n_x*1+n_y*xdim5_PdV_kernel_predict*1+n_z*xdim5_PdV_kernel_predict*ydim5_PdV_kernel_predict*1+x+xdim5_PdV_kernel_predict*(y)+xdim5_PdV_kernel_predict*ydim5_PdV_kernel_predict*(z))
#define OPS_ACC6(x,y,z) (n_x*1+n_y*xdim6_PdV_kernel_predict*1+n_z*xdim6_PdV_kernel_predict*ydim6_PdV_kernel_predict*1+x+xdim6_PdV_kernel_predict*(y)+xdim6_PdV_kernel_predict*ydim6_PdV_kernel_predict*(z))
#define OPS_ACC7(x,y,z) (n_x*1+n_y*xdim7_PdV_kernel_predict*1+n_z*xdim7_PdV_kernel_predict*ydim7_PdV_kernel_predict*1+x+xdim7_PdV_kernel_predict*(y)+xdim7_PdV_kernel_predict*ydim7_PdV_kernel_predict*(z))
#define OPS_ACC8(x,y,z) (n_x*1+n_y*xdim8_PdV_kernel_predict*1+n_z*xdim8_PdV_kernel_predict*ydim8_PdV_kernel_predict*1+x+xdim8_PdV_kernel_predict*(y)+xdim8_PdV_kernel_predict*ydim8_PdV_kernel_predict*(z))
#define OPS_ACC9(x,y,z) (n_x*1+n_y*xdim9_PdV_kernel_predict*1+n_z*xdim9_PdV_kernel_predict*ydim9_PdV_kernel_predict*1+x+xdim9_PdV_kernel_predict*(y)+xdim9_PdV_kernel_predict*ydim9_PdV_kernel_predict*(z))
#define OPS_ACC10(x,y,z) (n_x*1+n_y*xdim10_PdV_kernel_predict*1+n_z*xdim10_PdV_kernel_predict*ydim10_PdV_kernel_predict*1+x+xdim10_PdV_kernel_predict*(y)+xdim10_PdV_kernel_predict*ydim10_PdV_kernel_predict*(z))
#define OPS_ACC11(x,y,z) (n_x*1+n_y*xdim11_PdV_kernel_predict*1+n_z*xdim11_PdV_kernel_predict*ydim11_PdV_kernel_predict*1+x+xdim11_PdV_kernel_predict*(y)+xdim11_PdV_kernel_predict*ydim11_PdV_kernel_predict*(z))
#define OPS_ACC12(x,y,z) (n_x*1+n_y*xdim12_PdV_kernel_predict*1+n_z*xdim12_PdV_kernel_predict*ydim12_PdV_kernel_predict*1+x+xdim12_PdV_kernel_predict*(y)+xdim12_PdV_kernel_predict*ydim12_PdV_kernel_predict*(z))
#define OPS_ACC13(x,y,z) (n_x*1+n_y*xdim13_PdV_kernel_predict*1+n_z*xdim13_PdV_kernel_predict*ydim13_PdV_kernel_predict*1+x+xdim13_PdV_kernel_predict*(y)+xdim13_PdV_kernel_predict*ydim13_PdV_kernel_predict*(z))

//user function



void PdV_kernel_predict_c_wrapper(
  const double * restrict xarea,
  const double * restrict xvel0,
  const double * restrict yarea,
  const double * restrict yvel0,
  double * restrict volume_change,
  const double * restrict volume,
  const double * restrict pressure,
  const double * restrict density0,
  double * restrict density1,
  const double * restrict viscosity,
  const double * restrict energy0,
  double * restrict energy1,
  const double * restrict zarea,
  const double * restrict zvel0,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        

  double recip_volume, energy_change;
  double right_flux, left_flux, top_flux, bottom_flux, back_flux, front_flux, total_flux;

  left_flux = ( xarea[OPS_ACC0(0,0,0)] * ( xvel0[OPS_ACC1(0,0,0)] + xvel0[OPS_ACC1(0,1,0)] +
                                           xvel0[OPS_ACC1(0,0,1)] + xvel0[OPS_ACC1(0,1,1)] +
                                           xvel0[OPS_ACC1(0,0,0)] + xvel0[OPS_ACC1(0,1,0)] +
                                           xvel0[OPS_ACC1(0,0,1)] + xvel0[OPS_ACC1(0,1,1)] ) ) * 0.125 * dt * 0.5;
  right_flux = ( xarea[OPS_ACC0(1,0,0)] * ( xvel0[OPS_ACC1(1,0,0)] + xvel0[OPS_ACC1(1,1,0)] +
                                            xvel0[OPS_ACC1(1,0,1)] + xvel0[OPS_ACC1(1,1,1)] +
                                            xvel0[OPS_ACC1(1,0,0)] + xvel0[OPS_ACC1(1,1,0)] +
                                            xvel0[OPS_ACC1(1,0,1)] + xvel0[OPS_ACC1(1,1,1)] ) ) * 0.125 * dt * 0.5;

  bottom_flux = ( yarea[OPS_ACC2(0,0,0)] * ( yvel0[OPS_ACC3(0,0,0)] + yvel0[OPS_ACC3(1,0,0)] +
                                             yvel0[OPS_ACC3(0,0,1)] + yvel0[OPS_ACC3(1,0,1)] +
                                             yvel0[OPS_ACC3(0,0,0)] + yvel0[OPS_ACC3(1,0,0)] +
                                             yvel0[OPS_ACC3(0,0,1)] + yvel0[OPS_ACC3(1,0,1)] ) ) * 0.125* dt * 0.5;
  top_flux = ( yarea[OPS_ACC2(0,1,0)] * ( yvel0[OPS_ACC3(0,1,0)] + yvel0[OPS_ACC3(1,1,0)] +
                                          yvel0[OPS_ACC3(0,1,1)] + yvel0[OPS_ACC3(1,1,1)] +
                                          yvel0[OPS_ACC3(0,1,0)] + yvel0[OPS_ACC3(1,1,0)] +
                                          yvel0[OPS_ACC3(0,1,1)] + yvel0[OPS_ACC3(1,1,1)] ) ) * 0.125 * dt * 0.5;

  back_flux = ( zarea[OPS_ACC12(0,0,0)] * ( zvel0[OPS_ACC13(0,0,0)] + zvel0[OPS_ACC13(1,0,0)] +
                                            zvel0[OPS_ACC13(0,1,0)] + zvel0[OPS_ACC13(1,1,0)] +
                                            zvel0[OPS_ACC13(0,0,0)] + zvel0[OPS_ACC13(1,0,0)] +
                                            zvel0[OPS_ACC13(0,1,0)] + zvel0[OPS_ACC13(1,1,0)] ) ) * 0.125* dt * 0.5;
  front_flux = ( zarea[OPS_ACC12(0,0,1)] * ( zvel0[OPS_ACC13(0,0,1)] + zvel0[OPS_ACC13(1,0,1)] +
                                             zvel0[OPS_ACC13(0,1,1)] + zvel0[OPS_ACC13(1,1,1)] +
                                             zvel0[OPS_ACC13(0,0,1)] + zvel0[OPS_ACC13(1,0,1)] +
                                             zvel0[OPS_ACC13(0,1,1)] + zvel0[OPS_ACC13(1,1,1)] ) ) * 0.125 * dt * 0.5;

  total_flux = right_flux - left_flux + top_flux - bottom_flux + front_flux - back_flux;

  volume_change[OPS_ACC4(0,0,0)] = (volume[OPS_ACC5(0,0,0)])/(volume[OPS_ACC5(0,0,0)] + total_flux);
  recip_volume = 1.0/volume[OPS_ACC5(0,0,0)];
  energy_change = ( pressure[OPS_ACC6(0,0,0)]/density0[OPS_ACC7(0,0,0)] +
                    viscosity[OPS_ACC9(0,0,0)]/density0[OPS_ACC7(0,0,0)] ) * total_flux * recip_volume;
  energy1[OPS_ACC11(0,0,0)] = energy0[OPS_ACC10(0,0,0)] - energy_change;
  density1[OPS_ACC8(0,0,0)] = density0[OPS_ACC7(0,0,0)] * volume_change[OPS_ACC4(0,0,0)];


      }
    }
  }
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
#undef OPS_ACC11
#undef OPS_ACC12
#undef OPS_ACC13

