//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

extern int xdim0_calc_dt_kernel_print;
extern int ydim0_calc_dt_kernel_print;
extern int xdim1_calc_dt_kernel_print;
extern int ydim1_calc_dt_kernel_print;
extern int xdim2_calc_dt_kernel_print;
extern int ydim2_calc_dt_kernel_print;
extern int xdim3_calc_dt_kernel_print;
extern int ydim3_calc_dt_kernel_print;
extern int xdim4_calc_dt_kernel_print;
extern int ydim4_calc_dt_kernel_print;
extern int xdim5_calc_dt_kernel_print;
extern int ydim5_calc_dt_kernel_print;
extern int xdim6_calc_dt_kernel_print;
extern int ydim6_calc_dt_kernel_print;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6

#define OPS_ACC0(x, y, z)                                                      \
  (x + xdim0_calc_dt_kernel_print * (y) +                                      \
   xdim0_calc_dt_kernel_print * ydim0_calc_dt_kernel_print * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (x + xdim1_calc_dt_kernel_print * (y) +                                      \
   xdim1_calc_dt_kernel_print * ydim1_calc_dt_kernel_print * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (x + xdim2_calc_dt_kernel_print * (y) +                                      \
   xdim2_calc_dt_kernel_print * ydim2_calc_dt_kernel_print * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (x + xdim3_calc_dt_kernel_print * (y) +                                      \
   xdim3_calc_dt_kernel_print * ydim3_calc_dt_kernel_print * (z))
#define OPS_ACC4(x, y, z)                                                      \
  (x + xdim4_calc_dt_kernel_print * (y) +                                      \
   xdim4_calc_dt_kernel_print * ydim4_calc_dt_kernel_print * (z))
#define OPS_ACC5(x, y, z)                                                      \
  (x + xdim5_calc_dt_kernel_print * (y) +                                      \
   xdim5_calc_dt_kernel_print * ydim5_calc_dt_kernel_print * (z))
#define OPS_ACC6(x, y, z)                                                      \
  (x + xdim6_calc_dt_kernel_print * (y) +                                      \
   xdim6_calc_dt_kernel_print * ydim6_calc_dt_kernel_print * (z))

// user function

void calc_dt_kernel_print_c_wrapper(
    double *p_a0, int base0, int tot0, double *p_a1, int base1, int tot1,
    double *p_a2, int base2, int tot2, double *p_a3, int base3, int tot3,
    double *p_a4, int base4, int tot4, double *p_a5, int base5, int tot5,
    double *p_a6, int base6, int tot6, double *p_a7, int x_size, int y_size,
    int z_size) {
  double p_a7_0 = p_a7[0];
  double p_a7_1 = p_a7[1];
  double p_a7_2 = p_a7[2];
  double p_a7_3 = p_a7[3];
  double p_a7_4 = p_a7[4];
  double p_a7_5 = p_a7[5];
  double p_a7_6 = p_a7[6];
  double p_a7_7 = p_a7[7];
  double p_a7_8 = p_a7[8];
  double p_a7_9 = p_a7[9];
  double p_a7_10 = p_a7[10];
  double p_a7_11 = p_a7[11];
  double p_a7_12 = p_a7[12];
  double p_a7_13 = p_a7[13];
  double p_a7_14 = p_a7[14];
  double p_a7_15 = p_a7[15];
  double p_a7_16 = p_a7[16];
  double p_a7_17 = p_a7[17];
  double p_a7_18 = p_a7[18];
  double p_a7_19 = p_a7[19];
  double p_a7_20 = p_a7[20];
  double p_a7_21 = p_a7[21];
  double p_a7_22 = p_a7[22];
  double p_a7_23 = p_a7[23];
  double p_a7_24 = p_a7[24];
  double p_a7_25 = p_a7[25];
  double p_a7_26 = p_a7[26];
  double p_a7_27 = p_a7[27];
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for num_teams(                     \
    OPS_threads) thread_limit(OPS_threads_for_block) collapse(                  \
    3) schedule(static, 1) map(                                                 \
    tofrom : p_a7_27) reduction(+ : p_a7_0) reduction(+ : p_a7_1) reduction(    \
    + : p_a7_2) reduction(+ : p_a7_3) reduction(+ : p_a7_4) reduction(          \
        + : p_a7_5) reduction(+ : p_a7_6) reduction(+ : p_a7_7) reduction(      \
            + : p_a7_8) reduction(+ : p_a7_9) reduction(                        \
                + : p_a7_10) reduction(+ : p_a7_11) reduction(                  \
                    + : p_a7_12) reduction(+ : p_a7_13) reduction(              \
                        + : p_a7_14) reduction(+ : p_a7_15) reduction(          \
                            + : p_a7_16) reduction(+ : p_a7_17) reduction(      \
                                + : p_a7_18) reduction(+ : p_a7_19) reduction(  \
                                    + : p_a7_20)                                \
                                        reduction(+ : p_a7_21) reduction(       \
                                            + : p_a7_22) reduction(             \
                                                + : p_a7_23) reduction(         \
                                                    + : p_a7_24) reduction(     \
                                                        + : p_a7_25) reduction( \
                                                            + : p_a7_26)        \
                                                                reduction(      \
                                                                    + : p_a7_27)
#endif
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {
        double p_a7_local[28];
        p_a7_local[0] = ZERO_double;
        p_a7_local[1] = ZERO_double;
        p_a7_local[2] = ZERO_double;
        p_a7_local[3] = ZERO_double;
        p_a7_local[4] = ZERO_double;
        p_a7_local[5] = ZERO_double;
        p_a7_local[6] = ZERO_double;
        p_a7_local[7] = ZERO_double;
        p_a7_local[8] = ZERO_double;
        p_a7_local[9] = ZERO_double;
        p_a7_local[10] = ZERO_double;
        p_a7_local[11] = ZERO_double;
        p_a7_local[12] = ZERO_double;
        p_a7_local[13] = ZERO_double;
        p_a7_local[14] = ZERO_double;
        p_a7_local[15] = ZERO_double;
        p_a7_local[16] = ZERO_double;
        p_a7_local[17] = ZERO_double;
        p_a7_local[18] = ZERO_double;
        p_a7_local[19] = ZERO_double;
        p_a7_local[20] = ZERO_double;
        p_a7_local[21] = ZERO_double;
        p_a7_local[22] = ZERO_double;
        p_a7_local[23] = ZERO_double;
        p_a7_local[24] = ZERO_double;
        p_a7_local[25] = ZERO_double;
        p_a7_local[26] = ZERO_double;
        p_a7_local[27] = ZERO_double;
        const double *xvel0 =
            p_a0 + base0 + n_x * 1 * 1 +
            n_y * xdim0_calc_dt_kernel_print * 1 * 1 +
            n_z * xdim0_calc_dt_kernel_print * ydim0_calc_dt_kernel_print * 1;

        const double *yvel0 =
            p_a1 + base1 + n_x * 1 * 1 +
            n_y * xdim1_calc_dt_kernel_print * 1 * 1 +
            n_z * xdim1_calc_dt_kernel_print * ydim1_calc_dt_kernel_print * 1;

        const double *zvel0 =
            p_a2 + base2 + n_x * 1 * 1 +
            n_y * xdim2_calc_dt_kernel_print * 1 * 1 +
            n_z * xdim2_calc_dt_kernel_print * ydim2_calc_dt_kernel_print * 1;

        const double *density0 =
            p_a3 + base3 + n_x * 1 * 1 +
            n_y * xdim3_calc_dt_kernel_print * 1 * 1 +
            n_z * xdim3_calc_dt_kernel_print * ydim3_calc_dt_kernel_print * 1;

        const double *energy0 =
            p_a4 + base4 + n_x * 1 * 1 +
            n_y * xdim4_calc_dt_kernel_print * 1 * 1 +
            n_z * xdim4_calc_dt_kernel_print * ydim4_calc_dt_kernel_print * 1;

        const double *pressure =
            p_a5 + base5 + n_x * 1 * 1 +
            n_y * xdim5_calc_dt_kernel_print * 1 * 1 +
            n_z * xdim5_calc_dt_kernel_print * ydim5_calc_dt_kernel_print * 1;

        const double *soundspeed =
            p_a6 + base6 + n_x * 1 * 1 +
            n_y * xdim6_calc_dt_kernel_print * 1 * 1 +
            n_z * xdim6_calc_dt_kernel_print * ydim6_calc_dt_kernel_print * 1;

        double *output = p_a7_local;

        output[0] = xvel0[OPS_ACC0(0, 0, 0)];
        output[1] = yvel0[OPS_ACC1(0, 0, 0)];
        output[2] = zvel0[OPS_ACC2(0, 0, 0)];
        output[3] = xvel0[OPS_ACC0(1, 0, 0)];
        output[4] = yvel0[OPS_ACC1(1, 0, 0)];
        output[5] = zvel0[OPS_ACC2(0, 0, 0)];
        output[6] = xvel0[OPS_ACC0(1, 1, 0)];
        output[7] = yvel0[OPS_ACC1(1, 1, 0)];
        output[8] = zvel0[OPS_ACC2(0, 0, 0)];
        output[9] = xvel0[OPS_ACC0(0, 1, 0)];
        output[10] = yvel0[OPS_ACC1(0, 1, 0)];
        output[11] = zvel0[OPS_ACC2(0, 0, 0)];
        output[12] = xvel0[OPS_ACC0(0, 0, 1)];
        output[13] = yvel0[OPS_ACC1(0, 0, 1)];
        output[14] = zvel0[OPS_ACC2(0, 0, 1)];
        output[15] = xvel0[OPS_ACC0(1, 0, 1)];
        output[16] = yvel0[OPS_ACC1(1, 0, 1)];
        output[17] = zvel0[OPS_ACC2(0, 0, 1)];
        output[18] = xvel0[OPS_ACC0(1, 1, 1)];
        output[19] = yvel0[OPS_ACC1(1, 1, 1)];
        output[20] = zvel0[OPS_ACC2(0, 0, 1)];
        output[21] = xvel0[OPS_ACC0(0, 1, 1)];
        output[22] = yvel0[OPS_ACC1(0, 1, 1)];
        output[23] = zvel0[OPS_ACC2(0, 0, 1)];
        output[24] = density0[OPS_ACC3(0, 0, 0)];
        output[25] = energy0[OPS_ACC4(0, 0, 0)];
        output[26] = pressure[OPS_ACC5(0, 0, 0)];
        output[27] = soundspeed[OPS_ACC6(0, 0, 0)];

        p_a7_0 += p_a7_local[0];
        p_a7_1 += p_a7_local[1];
        p_a7_2 += p_a7_local[2];
        p_a7_3 += p_a7_local[3];
        p_a7_4 += p_a7_local[4];
        p_a7_5 += p_a7_local[5];
        p_a7_6 += p_a7_local[6];
        p_a7_7 += p_a7_local[7];
        p_a7_8 += p_a7_local[8];
        p_a7_9 += p_a7_local[9];
        p_a7_10 += p_a7_local[10];
        p_a7_11 += p_a7_local[11];
        p_a7_12 += p_a7_local[12];
        p_a7_13 += p_a7_local[13];
        p_a7_14 += p_a7_local[14];
        p_a7_15 += p_a7_local[15];
        p_a7_16 += p_a7_local[16];
        p_a7_17 += p_a7_local[17];
        p_a7_18 += p_a7_local[18];
        p_a7_19 += p_a7_local[19];
        p_a7_20 += p_a7_local[20];
        p_a7_21 += p_a7_local[21];
        p_a7_22 += p_a7_local[22];
        p_a7_23 += p_a7_local[23];
        p_a7_24 += p_a7_local[24];
        p_a7_25 += p_a7_local[25];
        p_a7_26 += p_a7_local[26];
        p_a7_27 += p_a7_local[27];
      }
    }
  }
  p_a7[0] = p_a7_0;
  p_a7[1] = p_a7_1;
  p_a7[2] = p_a7_2;
  p_a7[3] = p_a7_3;
  p_a7[4] = p_a7_4;
  p_a7[5] = p_a7_5;
  p_a7[6] = p_a7_6;
  p_a7[7] = p_a7_7;
  p_a7[8] = p_a7_8;
  p_a7[9] = p_a7_9;
  p_a7[10] = p_a7_10;
  p_a7[11] = p_a7_11;
  p_a7[12] = p_a7_12;
  p_a7[13] = p_a7_13;
  p_a7[14] = p_a7_14;
  p_a7[15] = p_a7_15;
  p_a7[16] = p_a7_16;
  p_a7[17] = p_a7_17;
  p_a7[18] = p_a7_18;
  p_a7[19] = p_a7_19;
  p_a7[20] = p_a7_20;
  p_a7[21] = p_a7_21;
  p_a7[22] = p_a7_22;
  p_a7[23] = p_a7_23;
  p_a7[24] = p_a7_24;
  p_a7[25] = p_a7_25;
  p_a7[26] = p_a7_26;
  p_a7[27] = p_a7_27;
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
