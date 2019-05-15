//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_poisson_kernel_update;
int xdim1_poisson_kernel_update;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x, y) (x + xdim0_poisson_kernel_update * (y))
#define OPS_ACC1(x, y) (x + xdim1_poisson_kernel_update * (y))

// user function
inline void poisson_kernel_update(const double *u2, double *u) {
  u[OPS_ACC1(0, 0)] = u2[OPS_ACC0(0, 0)];
}

#undef OPS_ACC0
#undef OPS_ACC1

void poisson_kernel_update_c_wrapper(double *p_a0, double *p_a1, int x_size,
                                     int y_size) {
#ifdef OPS_GPU
#pragma acc parallel deviceptr(p_a0, p_a1)
#pragma acc loop
#endif
  for (int n_y = 0; n_y < y_size; n_y++) {
#ifdef OPS_GPU
#pragma acc loop
#endif
    for (int n_x = 0; n_x < x_size; n_x++) {
      poisson_kernel_update(
          p_a0 + n_x * 1 * 1 + n_y * xdim0_poisson_kernel_update * 1 * 1,
          p_a1 + n_x * 1 * 1 + n_y * xdim1_poisson_kernel_update * 1 * 1);
    }
  }
}
