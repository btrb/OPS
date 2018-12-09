//
// auto-generated by ops.py
//

int xdim0_advec_cell_kernel2_xdir;
int xdim1_advec_cell_kernel2_xdir;
int xdim2_advec_cell_kernel2_xdir;
int xdim3_advec_cell_kernel2_xdir;


#define OPS_ACC0(x,y) (n_x*1+n_y*xdim0_advec_cell_kernel2_xdir*1+x+xdim0_advec_cell_kernel2_xdir*(y))
#define OPS_ACC1(x,y) (n_x*1+n_y*xdim1_advec_cell_kernel2_xdir*1+x+xdim1_advec_cell_kernel2_xdir*(y))
#define OPS_ACC2(x,y) (n_x*1+n_y*xdim2_advec_cell_kernel2_xdir*1+x+xdim2_advec_cell_kernel2_xdir*(y))
#define OPS_ACC3(x,y) (n_x*1+n_y*xdim3_advec_cell_kernel2_xdir*1+x+xdim3_advec_cell_kernel2_xdir*(y))

//user function



void advec_cell_kernel2_xdir_c_wrapper(
  double * restrict pre_vol,
  double * restrict post_vol,
  const double * restrict volume,
  const double * restrict vol_flux_x,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      

  pre_vol[OPS_ACC0(0,0)] = volume[OPS_ACC2(0,0)] + vol_flux_x[OPS_ACC3(1,0)] - vol_flux_x[OPS_ACC3(0,0)];
  post_vol[OPS_ACC1(0,0)] = volume[OPS_ACC2(0,0)];


    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

