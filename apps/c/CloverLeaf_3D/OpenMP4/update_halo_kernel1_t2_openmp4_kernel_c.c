//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_update_halo_kernel1_t2;
extern int ydim0_update_halo_kernel1_t2;
extern int xdim1_update_halo_kernel1_t2;
extern int ydim1_update_halo_kernel1_t2;
extern int xdim2_update_halo_kernel1_t2;
extern int ydim2_update_halo_kernel1_t2;
extern int xdim3_update_halo_kernel1_t2;
extern int ydim3_update_halo_kernel1_t2;
extern int xdim4_update_halo_kernel1_t2;
extern int ydim4_update_halo_kernel1_t2;
extern int xdim5_update_halo_kernel1_t2;
extern int ydim5_update_halo_kernel1_t2;
extern int xdim6_update_halo_kernel1_t2;
extern int ydim6_update_halo_kernel1_t2;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6

#define OPS_ACC0(x, y, z)                                                      \
  (x + xdim0_update_halo_kernel1_t2 * (y) +                                    \
   xdim0_update_halo_kernel1_t2 * ydim0_update_halo_kernel1_t2 * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (x + xdim1_update_halo_kernel1_t2 * (y) +                                    \
   xdim1_update_halo_kernel1_t2 * ydim1_update_halo_kernel1_t2 * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (x + xdim2_update_halo_kernel1_t2 * (y) +                                    \
   xdim2_update_halo_kernel1_t2 * ydim2_update_halo_kernel1_t2 * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (x + xdim3_update_halo_kernel1_t2 * (y) +                                    \
   xdim3_update_halo_kernel1_t2 * ydim3_update_halo_kernel1_t2 * (z))
#define OPS_ACC4(x, y, z)                                                      \
  (x + xdim4_update_halo_kernel1_t2 * (y) +                                    \
   xdim4_update_halo_kernel1_t2 * ydim4_update_halo_kernel1_t2 * (z))
#define OPS_ACC5(x, y, z)                                                      \
  (x + xdim5_update_halo_kernel1_t2 * (y) +                                    \
   xdim5_update_halo_kernel1_t2 * ydim5_update_halo_kernel1_t2 * (z))
#define OPS_ACC6(x, y, z)                                                      \
  (x + xdim6_update_halo_kernel1_t2 * (y) +                                    \
   xdim6_update_halo_kernel1_t2 * ydim6_update_halo_kernel1_t2 * (z))

// user function

void update_halo_kernel1_t2_c_wrapper(
    double *p_a0, int base0, int tot0, double *p_a1, int base1, int tot1,
    double *p_a2, int base2, int tot2, double *p_a3, int base3, int tot3,
    double *p_a4, int base4, int tot4, double *p_a5, int base5, int tot5,
    double *p_a6, int base6, int tot6, int *p_a7, int tot7, int x_size,
    int y_size, int z_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for num_teams(OPS_threads)        \
    thread_limit(OPS_threads_for_block) collapse(3) schedule(static, 1)
#endif
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {
        double *density0 = p_a0 + base0 + n_x * 1 * 1 +
                           n_y * xdim0_update_halo_kernel1_t2 * 1 * 1 +
                           n_z * xdim0_update_halo_kernel1_t2 *
                               ydim0_update_halo_kernel1_t2 * 1;

        double *density1 = p_a1 + base1 + n_x * 1 * 1 +
                           n_y * xdim1_update_halo_kernel1_t2 * 1 * 1 +
                           n_z * xdim1_update_halo_kernel1_t2 *
                               ydim1_update_halo_kernel1_t2 * 1;

        double *energy0 = p_a2 + base2 + n_x * 1 * 1 +
                          n_y * xdim2_update_halo_kernel1_t2 * 1 * 1 +
                          n_z * xdim2_update_halo_kernel1_t2 *
                              ydim2_update_halo_kernel1_t2 * 1;

        double *energy1 = p_a3 + base3 + n_x * 1 * 1 +
                          n_y * xdim3_update_halo_kernel1_t2 * 1 * 1 +
                          n_z * xdim3_update_halo_kernel1_t2 *
                              ydim3_update_halo_kernel1_t2 * 1;

        double *pressure = p_a4 + base4 + n_x * 1 * 1 +
                           n_y * xdim4_update_halo_kernel1_t2 * 1 * 1 +
                           n_z * xdim4_update_halo_kernel1_t2 *
                               ydim4_update_halo_kernel1_t2 * 1;

        double *viscosity = p_a5 + base5 + n_x * 1 * 1 +
                            n_y * xdim5_update_halo_kernel1_t2 * 1 * 1 +
                            n_z * xdim5_update_halo_kernel1_t2 *
                                ydim5_update_halo_kernel1_t2 * 1;

        double *soundspeed = p_a6 + base6 + n_x * 1 * 1 +
                             n_y * xdim6_update_halo_kernel1_t2 * 1 * 1 +
                             n_z * xdim6_update_halo_kernel1_t2 *
                                 ydim6_update_halo_kernel1_t2 * 1;

        const int *fields = p_a7;

        if (fields[FIELD_DENSITY0] == 1)
          density0[OPS_ACC0(0, 0, 0)] = density0[OPS_ACC0(0, -3, 0)];
        if (fields[FIELD_DENSITY1] == 1)
          density1[OPS_ACC1(0, 0, 0)] = density1[OPS_ACC1(0, -3, 0)];
        if (fields[FIELD_ENERGY0] == 1)
          energy0[OPS_ACC2(0, 0, 0)] = energy0[OPS_ACC2(0, -3, 0)];
        if (fields[FIELD_ENERGY1] == 1)
          energy1[OPS_ACC3(0, 0, 0)] = energy1[OPS_ACC3(0, -3, 0)];
        if (fields[FIELD_PRESSURE] == 1)
          pressure[OPS_ACC4(0, 0, 0)] = pressure[OPS_ACC4(0, -3, 0)];
        if (fields[FIELD_VISCOSITY] == 1)
          viscosity[OPS_ACC5(0, 0, 0)] = viscosity[OPS_ACC5(0, -3, 0)];
        if (fields[FIELD_SOUNDSPEED] == 1)
          soundspeed[OPS_ACC6(0, 0, 0)] = soundspeed[OPS_ACC6(0, -3, 0)];
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
