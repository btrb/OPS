//
// auto-generated by op2.py on 2014-03-06 15:57
//

//header
#include "ops_lib_cpp.h"
#include "ops_cuda_rt_support.h"
#include "ops_cuda_reduction.h"

// global constants

void ops_decl_const_char(int dim, char const *type,
int size, char *dat, char const *name){
  {
    printf("error: unknown const name\n"); exit(1);
  }
}


//user kernel files
#include "revert_kernel_cuda_kernel.cu"
#include "reset_field_kernel1_cuda_kernel.cu"
#include "reset_field_kernel2_cuda_kernel.cu"
#include "ideal_gas_kernel_cuda_kernel.cu"
#include "PdV_kernel_predict_cuda_kernel.cu"
#include "PdV_kernel_nopredict_cuda_kernel.cu"
#include "accelerate_kernel_cuda_kernel.cu"
#include "advec_cell_kernel1_xdir_cuda_kernel.cu"
#include "advec_cell_kernel2_xdir_cuda_kernel.cu"
#include "advec_cell_kernel3_xdir_cuda_kernel.cu"
#include "advec_cell_kernel4_xdir_cuda_kernel.cu"
#include "advec_cell_kernel1_ydir_cuda_kernel.cu"
#include "advec_cell_kernel2_ydir_cuda_kernel.cu"
#include "advec_cell_kernel3_ydir_cuda_kernel.cu"
#include "advec_cell_kernel4_ydir_cuda_kernel.cu"
#include "advec_mom_kernel_x1_cuda_kernel.cu"
#include "advec_mom_kernel_y1_cuda_kernel.cu"
#include "advec_mom_kernel_x2_cuda_kernel.cu"
#include "advec_mom_kernel_y2_cuda_kernel.cu"
#include "advec_mom_kernel_mass_flux_x_cuda_kernel.cu"
#include "advec_mom_kernel_post_pre_advec_x_cuda_kernel.cu"
#include "advec_mom_kernel1_x_nonvector_cuda_kernel.cu"
#include "advec_mom_kernel2_x_cuda_kernel.cu"
#include "advec_mom_kernel_mass_flux_y_cuda_kernel.cu"
#include "advec_mom_kernel_post_pre_advec_y_cuda_kernel.cu"
#include "advec_mom_kernel1_y_nonvector_cuda_kernel.cu"
#include "advec_mom_kernel2_y_cuda_kernel.cu"
#include "calc_dt_kernel_cuda_kernel.cu"
#include "calc_dt_kernel_min_cuda_kernel.cu"
#include "calc_dt_kernel_get_cuda_kernel.cu"
#include "calc_dt_kernel_print_cuda_kernel.cu"
#include "field_summary_kernel_cuda_kernel.cu"
#include "flux_calc_kernelx_cuda_kernel.cu"
#include "flux_calc_kernely_cuda_kernel.cu"
#include "viscosity_kernel_cuda_kernel.cu"
#include "update_halo_kernel1_b2_cuda_kernel.cu"
#include "update_halo_kernel_b1_cuda_kernel.cu"
#include "update_halo_kernel_t2_cuda_kernel.cu"
#include "update_halo_kernel_t1_cuda_kernel.cu"
#include "update_halo_kernel1_l2_cuda_kernel.cu"
#include "update_halo_kernel1_l1_cuda_kernel.cu"
#include "update_halo_kernel1_r2_cuda_kernel.cu"
#include "update_halo_kernel1_r1_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_plus_4_a_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_plus_2_a_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_plus_4_b_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_plus_2_b_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_minus_4_a_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_minus_2_a_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_minus_4_b_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_minus_2_b_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_minus_4_a_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_minus_2_a_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_minus_4_b_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_minus_2_b_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_plus_4_a_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_plus_2_a_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_plus_4_b_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_plus_2_b_cuda_kernel.cu"
#include "update_halo_kernel3_plus_4_a_cuda_kernel.cu"
#include "update_halo_kernel3_plus_2_a_cuda_kernel.cu"
#include "update_halo_kernel3_plus_4_b_cuda_kernel.cu"
#include "update_halo_kernel3_plus_2_b_cuda_kernel.cu"
#include "update_halo_kernel3_minus_4_a_cuda_kernel.cu"
#include "update_halo_kernel3_minus_2_a_cuda_kernel.cu"
#include "update_halo_kernel3_minus_4_b_cuda_kernel.cu"
#include "update_halo_kernel3_minus_2_b_cuda_kernel.cu"
#include "update_halo_kernel4_minus_4_a_cuda_kernel.cu"
#include "update_halo_kernel4_minus_2_a_cuda_kernel.cu"
#include "update_halo_kernel4_minus_4_b_cuda_kernel.cu"
#include "update_halo_kernel4_minus_2_b_cuda_kernel.cu"
#include "update_halo_kernel4_plus_4_a_cuda_kernel.cu"
#include "update_halo_kernel4_plus_2_a_cuda_kernel.cu"
#include "update_halo_kernel4_plus_4_b_cuda_kernel.cu"
#include "update_halo_kernel4_plus_2_b_cuda_kernel.cu"
#include "initialise_chunk_kernel_x_cuda_kernel.cu"
#include "initialise_chunk_kernel_y_cuda_kernel.cu"
#include "initialise_chunk_kernel_cellx_cuda_kernel.cu"
#include "initialise_chunk_kernel_celly_cuda_kernel.cu"
#include "initialise_chunk_kernel_volume_cuda_kernel.cu"
#include "generate_chunk_kernel_cuda_kernel.cu"
