#define _GNU_SOURCE
#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#define sys_kernel_2d_memcpy 447
int main(int argc, char **argv)
{
  float arr[2][2] ={{1,2},{2,3}};
 
  float (*ptr)[2] = arr;


float a[2][2];
float (*ptr2)[2] = a;



int long am = syscall(sys_kernel_2d_memcpy,arr,a,2,2);
for (int x=0 ; x < 2; x++)
{
  for (int y=0 ; y < 2; y++)
  {
    printf("%f\n",a[x][y]);
  }
}

if(am==0){
	printf("Syscall Returned 0\nSuccess!\n");
}
else {
printf("Syscall Returned  \n" );

}
return 0;
}