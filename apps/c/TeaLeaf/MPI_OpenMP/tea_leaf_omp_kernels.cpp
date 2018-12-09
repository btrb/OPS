//
// auto-generated by ops.py//

//header
#define OPS_2D
#define OPS_ACC_MD_MACROS
#include "ops_lib_cpp.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
#include "user_types.h"

//set max number of OMP threads for reductions
#ifndef MAX_REDUCT_THREADS
#define MAX_REDUCT_THREADS 64
#endif
//global constants
extern field_type field;
extern grid_type grid;
extern int number_of_states;
extern state_type *states;
extern int g_circ;
extern int g_point;
extern int g_rect;


void ops_init_backend() {}

//user kernel files
#include "field_summary_kernel_omp_kernel.cpp"
#include "generate_chunk_kernel_omp_kernel.cpp"
#include "initialise_chunk_kernel_zero_omp_kernel.cpp"
#include "initialise_chunk_kernel_zero_x_omp_kernel.cpp"
#include "initialise_chunk_kernel_zero_y_omp_kernel.cpp"
#include "initialise_chunk_kernel_xx_omp_kernel.cpp"
#include "initialise_chunk_kernel_yy_omp_kernel.cpp"
#include "initialise_chunk_kernel_x_omp_kernel.cpp"
#include "initialise_chunk_kernel_y_omp_kernel.cpp"
#include "initialise_chunk_kernel_cellx_omp_kernel.cpp"
#include "initialise_chunk_kernel_celly_omp_kernel.cpp"
#include "initialise_chunk_kernel_volume_omp_kernel.cpp"
#include "set_field_kernel_omp_kernel.cpp"
#include "tea_leaf_init_zero2_kernel_omp_kernel.cpp"
#include "tea_leaf_yeqx_kernel_omp_kernel.cpp"
#include "tea_leaf_dot_kernel_omp_kernel.cpp"
#include "tea_leaf_cg_calc_w_reduce_kernel_omp_kernel.cpp"
#include "tea_leaf_axpy_kernel_omp_kernel.cpp"
#include "tea_leaf_cg_calc_ur_r_reduce_kernel_omp_kernel.cpp"
#include "tea_leaf_axpby_kernel_omp_kernel.cpp"
#include "tea_leaf_cheby_init_kernel_omp_kernel.cpp"
#include "tea_leaf_recip3_kernel_omp_kernel.cpp"
#include "tea_leaf_xpy_kernel_omp_kernel.cpp"
#include "tea_leaf_common_init_u_u0_kernel_omp_kernel.cpp"
#include "tea_leaf_recip_kernel_omp_kernel.cpp"
#include "tea_leaf_common_init_Kx_Ky_kernel_omp_kernel.cpp"
#include "tea_leaf_init_zero_kernel_omp_kernel.cpp"
#include "tea_leaf_common_init_kernel_omp_kernel.cpp"
#include "tea_leaf_recip2_kernel_omp_kernel.cpp"
#include "tea_leaf_common_residual_kernel_omp_kernel.cpp"
#include "tea_leaf_norm2_kernel_omp_kernel.cpp"
#include "tea_leaf_common_init_diag_init_kernel_omp_kernel.cpp"
#include "tea_leaf_zeqxty_kernel_omp_kernel.cpp"
#include "tea_leaf_jacobi_kernel_omp_kernel.cpp"
#include "tea_leaf_ppcg_init1_kernel_omp_kernel.cpp"
#include "tea_leaf_ppcg_init2_kernel_omp_kernel.cpp"
#include "tea_leaf_ppcg_inner1_kernel_omp_kernel.cpp"
#include "tea_leaf_ppcg_inner2_kernel_omp_kernel.cpp"
#include "tea_leaf_ppcg_reduce_kernel_omp_kernel.cpp"
#include "update_halo_kernel1_b2_omp_kernel.cpp"
#include "update_halo_kernel1_b1_omp_kernel.cpp"
#include "update_halo_kernel1_t2_omp_kernel.cpp"
#include "update_halo_kernel1_t1_omp_kernel.cpp"
#include "update_halo_kernel1_l2_omp_kernel.cpp"
#include "update_halo_kernel1_l1_omp_kernel.cpp"
#include "update_halo_kernel1_r2_omp_kernel.cpp"
#include "update_halo_kernel1_r1_omp_kernel.cpp"
