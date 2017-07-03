//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_flux_calc_kernely;
extern int ydim0_flux_calc_kernely;
extern int xdim1_flux_calc_kernely;
extern int ydim1_flux_calc_kernely;
extern int xdim2_flux_calc_kernely;
extern int ydim2_flux_calc_kernely;
extern int xdim3_flux_calc_kernely;
extern int ydim3_flux_calc_kernely;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y, z)                                                      \
  (x + xdim0_flux_calc_kernely * (y) +                                         \
   xdim0_flux_calc_kernely * ydim0_flux_calc_kernely * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (x + xdim1_flux_calc_kernely * (y) +                                         \
   xdim1_flux_calc_kernely * ydim1_flux_calc_kernely * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (x + xdim2_flux_calc_kernely * (y) +                                         \
   xdim2_flux_calc_kernely * ydim2_flux_calc_kernely * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (x + xdim3_flux_calc_kernely * (y) +                                         \
   xdim3_flux_calc_kernely * ydim3_flux_calc_kernely * (z))

// user function

void flux_calc_kernely_c_wrapper(double *p_a0, int base0, int tot0,
                                 double *p_a1, int base1, int tot1,
                                 double *p_a2, int base2, int tot2,
                                 double *p_a3, int base3, int tot3, int x_size,
                                 int y_size, int z_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for num_teams(OPS_threads)        \
    thread_limit(OPS_threads_for_block) collapse(3) schedule(static, 1)
#endif
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {
        double *vol_flux_y =
            p_a0 + base0 + n_x * 1 * 1 + n_y * xdim0_flux_calc_kernely * 1 * 1 +
            n_z * xdim0_flux_calc_kernely * ydim0_flux_calc_kernely * 1;

        const double *yarea =
            p_a1 + base1 + n_x * 1 * 1 + n_y * xdim1_flux_calc_kernely * 1 * 1 +
            n_z * xdim1_flux_calc_kernely * ydim1_flux_calc_kernely * 1;

        const double *yvel0 =
            p_a2 + base2 + n_x * 1 * 1 + n_y * xdim2_flux_calc_kernely * 1 * 1 +
            n_z * xdim2_flux_calc_kernely * ydim2_flux_calc_kernely * 1;

        const double *yvel1 =
            p_a3 + base3 + n_x * 1 * 1 + n_y * xdim3_flux_calc_kernely * 1 * 1 +
            n_z * xdim3_flux_calc_kernely * ydim3_flux_calc_kernely * 1;

        vol_flux_y[OPS_ACC0(0, 0, 0)] =
            0.125 * dt * (yarea[OPS_ACC1(0, 0, 0)]) *
            (yvel0[OPS_ACC2(0, 0, 0)] + yvel0[OPS_ACC2(1, 0, 0)] +
             yvel0[OPS_ACC2(0, 0, 1)] + yvel0[OPS_ACC2(1, 0, 1)] +
             yvel1[OPS_ACC3(0, 0, 0)] + yvel1[OPS_ACC3(1, 0, 0)] +
             yvel1[OPS_ACC3(0, 0, 1)] + yvel1[OPS_ACC3(1, 0, 1)]);
      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
