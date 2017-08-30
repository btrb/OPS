//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_advec_mom_kernel2_x;
extern int xdim1_advec_mom_kernel2_x;
extern int xdim2_advec_mom_kernel2_x;
extern int xdim3_advec_mom_kernel2_x;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_advec_mom_kernel2_x * 1 * 1 + x +                 \
   xdim0_advec_mom_kernel2_x * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim1_advec_mom_kernel2_x * 1 * 1 + x +                 \
   xdim1_advec_mom_kernel2_x * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim2_advec_mom_kernel2_x * 1 * 1 + x +                 \
   xdim2_advec_mom_kernel2_x * (y))
#define OPS_ACC3(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim3_advec_mom_kernel2_x * 1 * 1 + x +                 \
   xdim3_advec_mom_kernel2_x * (y))

// user function

void advec_mom_kernel2_x_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                                   double *p_a3, int x_size, int y_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for schedule(static, 1)
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    int n_x = i % x_size;
    int n_y = i / x_size;
    double *vel1 = p_a0;

    const double *node_mass_post = p_a1;
    const double *node_mass_pre = p_a2;

    const double *mom_flux = p_a3;

    vel1[OPS_ACC0(0, 0)] =
        (vel1[OPS_ACC0(0, 0)] * node_mass_pre[OPS_ACC2(0, 0)] +
         mom_flux[OPS_ACC3(-1, 0)] - mom_flux[OPS_ACC3(0, 0)]) /
        node_mass_post[OPS_ACC1(0, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
