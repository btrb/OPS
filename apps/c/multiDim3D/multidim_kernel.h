#ifndef MULTIDIM_KERNEL_H
#define MULTIDIM_KERNEL_H

void multidim_kernel(double *val, int *idx){
  val[OPS_ACC_MD0(0,0,0,0)] = (double)(idx[0]);
  val[OPS_ACC_MD0(1,0,0,0)] = (double)(idx[1]);
  val[OPS_ACC_MD0(2,0,0,0)] = (double)(idx[2]);
  printf("%d %d %d: %p %p %p\n",idx[0],idx[1],idx[2],&val[OPS_ACC_MD0(0,0,0,0)],&val[OPS_ACC_MD0(1,0,0,0)], &val[OPS_ACC_MD0(2,0,0,0)]);
}

#endif //MULTIDIM_KERNEL_H
