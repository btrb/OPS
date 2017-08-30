//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_update_halo_kernel2_xvel_plus_4_a;
extern int xdim1_update_halo_kernel2_xvel_plus_4_a;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_update_halo_kernel2_xvel_plus_4_a * 1 * 1 + x +   \
   xdim0_update_halo_kernel2_xvel_plus_4_a * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim1_update_halo_kernel2_xvel_plus_4_a * 1 * 1 + x +   \
   xdim1_update_halo_kernel2_xvel_plus_4_a * (y))

// user function

void update_halo_kernel2_xvel_plus_4_a_c_wrapper(double *p_a0, double *p_a1,
                                                 int *p_a2, int x_size,
                                                 int y_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for schedule(static, 1)
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    int n_x = i % x_size;
    int n_y = i / x_size;
    double *xvel0 = p_a0;

    double *xvel1 = p_a1;
    const int *fields = p_a2;

    if (fields[FIELD_XVEL0] == 1)
      xvel0[OPS_ACC0(0, 0)] = xvel0[OPS_ACC0(0, 4)];
    if (fields[FIELD_XVEL1] == 1)
      xvel1[OPS_ACC1(0, 0)] = xvel1[OPS_ACC1(0, 4)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
