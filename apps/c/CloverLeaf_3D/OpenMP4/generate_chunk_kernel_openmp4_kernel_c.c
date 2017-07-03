//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_generate_chunk_kernel;
extern int ydim0_generate_chunk_kernel;
extern int xdim1_generate_chunk_kernel;
extern int ydim1_generate_chunk_kernel;
extern int xdim2_generate_chunk_kernel;
extern int ydim2_generate_chunk_kernel;
extern int xdim3_generate_chunk_kernel;
extern int ydim3_generate_chunk_kernel;
extern int xdim4_generate_chunk_kernel;
extern int ydim4_generate_chunk_kernel;
extern int xdim5_generate_chunk_kernel;
extern int ydim5_generate_chunk_kernel;
extern int xdim6_generate_chunk_kernel;
extern int ydim6_generate_chunk_kernel;
extern int xdim7_generate_chunk_kernel;
extern int ydim7_generate_chunk_kernel;
extern int xdim8_generate_chunk_kernel;
extern int ydim8_generate_chunk_kernel;
extern int xdim9_generate_chunk_kernel;
extern int ydim9_generate_chunk_kernel;
extern int xdim10_generate_chunk_kernel;
extern int ydim10_generate_chunk_kernel;

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

#define OPS_ACC0(x, y, z)                                                      \
  (x + xdim0_generate_chunk_kernel * (y) +                                     \
   xdim0_generate_chunk_kernel * ydim0_generate_chunk_kernel * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (x + xdim1_generate_chunk_kernel * (y) +                                     \
   xdim1_generate_chunk_kernel * ydim1_generate_chunk_kernel * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (x + xdim2_generate_chunk_kernel * (y) +                                     \
   xdim2_generate_chunk_kernel * ydim2_generate_chunk_kernel * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (x + xdim3_generate_chunk_kernel * (y) +                                     \
   xdim3_generate_chunk_kernel * ydim3_generate_chunk_kernel * (z))
#define OPS_ACC4(x, y, z)                                                      \
  (x + xdim4_generate_chunk_kernel * (y) +                                     \
   xdim4_generate_chunk_kernel * ydim4_generate_chunk_kernel * (z))
#define OPS_ACC5(x, y, z)                                                      \
  (x + xdim5_generate_chunk_kernel * (y) +                                     \
   xdim5_generate_chunk_kernel * ydim5_generate_chunk_kernel * (z))
#define OPS_ACC6(x, y, z)                                                      \
  (x + xdim6_generate_chunk_kernel * (y) +                                     \
   xdim6_generate_chunk_kernel * ydim6_generate_chunk_kernel * (z))
#define OPS_ACC7(x, y, z)                                                      \
  (x + xdim7_generate_chunk_kernel * (y) +                                     \
   xdim7_generate_chunk_kernel * ydim7_generate_chunk_kernel * (z))
#define OPS_ACC8(x, y, z)                                                      \
  (x + xdim8_generate_chunk_kernel * (y) +                                     \
   xdim8_generate_chunk_kernel * ydim8_generate_chunk_kernel * (z))
#define OPS_ACC9(x, y, z)                                                      \
  (x + xdim9_generate_chunk_kernel * (y) +                                     \
   xdim9_generate_chunk_kernel * ydim9_generate_chunk_kernel * (z))
#define OPS_ACC10(x, y, z)                                                     \
  (x + xdim10_generate_chunk_kernel * (y) +                                    \
   xdim10_generate_chunk_kernel * ydim10_generate_chunk_kernel * (z))

// user function

void generate_chunk_kernel_c_wrapper(
    double *p_a0, int base0, int tot0, double *p_a1, int base1, int tot1,
    double *p_a2, int base2, int tot2, double *p_a3, int base3, int tot3,
    double *p_a4, int base4, int tot4, double *p_a5, int base5, int tot5,
    double *p_a6, int base6, int tot6, double *p_a7, int base7, int tot7,
    double *p_a8, int base8, int tot8, double *p_a9, int base9, int tot9,
    double *p_a10, int base10, int tot10, int x_size, int y_size, int z_size) {
#ifdef OPS_GPU
#pragma omp target enter data map(to:states[0:2])
#pragma omp target teams distribute parallel for num_teams(OPS_threads)        \
    thread_limit(OPS_threads_for_block) collapse(3) schedule(static, 1)
#endif
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {
        const double *vertexx =
            p_a0 + base0 + n_x * 1 * 1 +
            n_y * xdim0_generate_chunk_kernel * 0 * 1 +
            n_z * xdim0_generate_chunk_kernel * ydim0_generate_chunk_kernel * 0;

        const double *vertexy =
            p_a1 + base1 + n_x * 0 * 1 +
            n_y * xdim1_generate_chunk_kernel * 1 * 1 +
            n_z * xdim1_generate_chunk_kernel * ydim1_generate_chunk_kernel * 0;

        const double *vertexz =
            p_a2 + base2 + n_x * 0 * 1 +
            n_y * xdim2_generate_chunk_kernel * 0 * 1 +
            n_z * xdim2_generate_chunk_kernel * ydim2_generate_chunk_kernel * 1;

        double *energy0 =
            p_a3 + base3 + n_x * 1 * 1 +
            n_y * xdim3_generate_chunk_kernel * 1 * 1 +
            n_z * xdim3_generate_chunk_kernel * ydim3_generate_chunk_kernel * 1;

        double *density0 =
            p_a4 + base4 + n_x * 1 * 1 +
            n_y * xdim4_generate_chunk_kernel * 1 * 1 +
            n_z * xdim4_generate_chunk_kernel * ydim4_generate_chunk_kernel * 1;

        double *xvel0 =
            p_a5 + base5 + n_x * 1 * 1 +
            n_y * xdim5_generate_chunk_kernel * 1 * 1 +
            n_z * xdim5_generate_chunk_kernel * ydim5_generate_chunk_kernel * 1;

        double *yvel0 =
            p_a6 + base6 + n_x * 1 * 1 +
            n_y * xdim6_generate_chunk_kernel * 1 * 1 +
            n_z * xdim6_generate_chunk_kernel * ydim6_generate_chunk_kernel * 1;

        double *zvel0 =
            p_a7 + base7 + n_x * 1 * 1 +
            n_y * xdim7_generate_chunk_kernel * 1 * 1 +
            n_z * xdim7_generate_chunk_kernel * ydim7_generate_chunk_kernel * 1;

        const double *cellx =
            p_a8 + base8 + n_x * 1 * 1 +
            n_y * xdim8_generate_chunk_kernel * 0 * 1 +
            n_z * xdim8_generate_chunk_kernel * ydim8_generate_chunk_kernel * 0;

        const double *celly =
            p_a9 + base9 + n_x * 0 * 1 +
            n_y * xdim9_generate_chunk_kernel * 1 * 1 +
            n_z * xdim9_generate_chunk_kernel * ydim9_generate_chunk_kernel * 0;

        const double *cellz = p_a10 + base10 + n_x * 0 * 1 +
                              n_y * xdim10_generate_chunk_kernel * 0 * 1 +
                              n_z * xdim10_generate_chunk_kernel *
                                  ydim10_generate_chunk_kernel * 1;

        double radius, x_cent, y_cent, z_cent;
        int is_in = 0;

        energy0[OPS_ACC3(0, 0, 0)] = states[0].energy;
        density0[OPS_ACC4(0, 0, 0)] = states[0].density;
        xvel0[OPS_ACC5(0, 0, 0)] = states[0].xvel;
        yvel0[OPS_ACC6(0, 0, 0)] = states[0].yvel;
        zvel0[OPS_ACC7(0, 0, 0)] = states[0].zvel;

        for (int i = 1; i < number_of_states; i++) {

          x_cent = states[i].xmin;
          y_cent = states[i].ymin;
          z_cent = states[i].zmin;

          if (states[i].geometry == g_cube) {
            for (int i1 = -1; i1 <= 0; i1++) {
              for (int j1 = -1; j1 <= 0; j1++) {
                for (int k1 = -1; k1 <= 0; k1++) {
                  if (vertexx[OPS_ACC0(1 + i1, 0, 0)] >= states[i].xmin &&
                      vertexx[OPS_ACC0(0 + i1, 0, 0)] < states[i].xmax) {
                    if (vertexy[OPS_ACC1(0, 1 + j1, 0)] >= states[i].ymin &&
                        vertexy[OPS_ACC1(0, 0 + j1, 0)] < states[i].ymax) {
                      if (vertexz[OPS_ACC2(0, 0, 1 + k1)] >= states[i].zmin &&
                          vertexz[OPS_ACC2(0, 0, 0 + k1)] < states[i].zmax) {
                        is_in = 1;
                      }
                    }
                  }
                }
              }
            }

            if (vertexx[OPS_ACC0(1, 0, 0)] >= states[i].xmin &&
                vertexx[OPS_ACC0(0, 0, 0)] < states[i].xmax) {
              if (vertexy[OPS_ACC1(0, 1, 0)] >= states[i].ymin &&
                  vertexy[OPS_ACC1(0, 0, 0)] < states[i].ymax) {
                if (vertexz[OPS_ACC2(0, 0, 1)] >= states[i].zmin &&
                    vertexz[OPS_ACC2(0, 0, 0)] < states[i].zmax) {
                  energy0[OPS_ACC3(0, 0, 0)] = states[i].energy;
                  density0[OPS_ACC4(0, 0, 0)] = states[i].density;
                }
              }
            }

            if (is_in) {
              xvel0[OPS_ACC5(0, 0, 0)] = states[i].xvel;
              yvel0[OPS_ACC6(0, 0, 0)] = states[i].yvel;
              zvel0[OPS_ACC7(0, 0, 0)] = states[i].zvel;
            }
          } else if (states[i].geometry == g_sphe) {
            for (int i1 = -1; i1 <= 0; i1++) {
              for (int j1 = -1; j1 <= 0; j1++) {
                for (int k1 = -1; k1 <= 0; k1++) {
                  radius = sqrt((cellx[OPS_ACC8(0, 0, 0)] - x_cent) *
                                    (cellx[OPS_ACC8(0, 0, 0)] - x_cent) +
                                (celly[OPS_ACC9(0, 0, 0)] - y_cent) *
                                    (celly[OPS_ACC9(0, 0, 0)] - y_cent) +
                                (cellz[OPS_ACC10(0, 0, 0)] - z_cent) *
                                    (cellz[OPS_ACC10(0, 0, 0)] - z_cent));
                  if (radius <= states[i].radius)
                    is_in = 1;
                }
              }
            }
            if (radius <= states[i].radius) {
              energy0[OPS_ACC3(0, 0, 0)] = states[i].energy;
              density0[OPS_ACC4(0, 0, 0)] = states[i].density;
            }
            if (is_in) {
              xvel0[OPS_ACC5(0, 0, 0)] = states[i].xvel;
              yvel0[OPS_ACC6(0, 0, 0)] = states[i].yvel;
              zvel0[OPS_ACC7(0, 0, 0)] = states[i].zvel;
            }
          } else if (states[i].geometry == g_point) {
            for (int i1 = -1; i1 <= 0; i1++) {
              for (int j1 = -1; j1 <= 0; j1++) {
                for (int k1 = -1; k1 <= 0; k1++) {
                  if (vertexx[OPS_ACC0(0 + i1, 0, 0)] == x_cent &&
                      vertexy[OPS_ACC1(0, 0 + j1, 0)] == y_cent &&
                      vertexz[OPS_ACC2(0, 0, 0 + k1)] == z_cent)
                    is_in = 1;
                }
              }
            }

            if (vertexx[OPS_ACC0(0, 0, 0)] == x_cent &&
                vertexy[OPS_ACC1(0, 0, 0)] == y_cent &&
                vertexz[OPS_ACC2(0, 0, 0)] == z_cent) {
              energy0[OPS_ACC3(0, 0, 0)] = states[i].energy;
              density0[OPS_ACC4(0, 0, 0)] = states[i].density;
            }
            if (is_in) {
              xvel0[OPS_ACC5(0, 0, 0)] = states[i].xvel;
              yvel0[OPS_ACC6(0, 0, 0)] = states[i].yvel;
              zvel0[OPS_ACC7(0, 0, 0)] = states[i].zvel;
            }
          }
        }
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
