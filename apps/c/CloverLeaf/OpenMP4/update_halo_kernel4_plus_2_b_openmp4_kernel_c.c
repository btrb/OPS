//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_update_halo_kernel4_plus_2_b;
extern int xdim1_update_halo_kernel4_plus_2_b;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_update_halo_kernel4_plus_2_b * 1 * 1 + x +        \
   xdim0_update_halo_kernel4_plus_2_b * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim1_update_halo_kernel4_plus_2_b * 1 * 1 + x +        \
   xdim1_update_halo_kernel4_plus_2_b * (y))

// user function

void update_halo_kernel4_plus_2_b_c_wrapper(double *p_a0, double *p_a1,
                                            int *p_a2, int x_size, int y_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for schedule(static, 1)
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    int n_x = i % x_size;
    int n_y = i / x_size;
    double *vol_flux_y = p_a0;

    double *mass_flux_y = p_a1;
    const int *fields = p_a2;

    if (fields[FIELD_VOL_FLUX_Y] == 1)
      vol_flux_y[OPS_ACC0(0, 0)] = vol_flux_y[OPS_ACC0(-2, 0)];
    if (fields[FIELD_MASS_FLUX_Y] == 1)
      mass_flux_y[OPS_ACC1(0, 0)] = mass_flux_y[OPS_ACC1(-2, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
