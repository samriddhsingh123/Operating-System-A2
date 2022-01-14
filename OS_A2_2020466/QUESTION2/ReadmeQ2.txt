I used linux-5.15.4(using config file given on the classroom on 24 nov) to do the below process:

1. we go to this directory: /home/kern/build2/linux-5.15.4/kernel/sys.c
	and we define the SYSCALL_DEFINE4(kernel_2d_memcpy,float __user *,src ,float __user *, dst,int, rows, int, cols)
	In this function src is a source for our initial array and we copied it in the the dst folder and rows is no of row
	and cols is no of columns.
	The system call is used to create a buffer to hold the data in kernel space. This space is 
	allocated using "kmalloc".
	In this we use "__copy_from_user" to copy the source array to the buffer in kernel space. Then
	"__copy_to_user" command is used to copy array from buffer back to user space in destination array  
2. we go to this directory: /home/kern/build2/linux-5.15.4/arch/x86/entry/syscalls/syscall_64.tbl
	and we give entry to our syscall in the syscall_64.tbl 449 common  kernel_2d_memcpy    sys_kernel_2d_memcpy
	which means at 449 now we added our function named kernel_2d_memcpy
3. Now we run make command and compile the whole system.
4. We make test.c to test our system call is working properly or not. 
	We hardcode to make the 2d matrix and assign its value and then we make empty matrix in which we 
	have to copy the given matrix using the syscall syscall(SYS_kernel_2d_memcpy,arr,abc,2,2);
	and then we check it by checking the return value of syscall.
	if this programm will not run then attachsys.c and syscall_64.tbl in respective directories 
5.PATCHFILE:
	we make patchfile for table named as PatchForSysCallDef.patch using the command
	"diff -u syscall_64.tbl syscall2_64.tbl > patchForTable.patch".
	we make patchfile for table named as patchForTable.patch using the command
	"diff -u sys.c sys2.c > PatchForSysCallDef in the directory".
	We attached the 4 c filee:
	sys.c = older sysfile

	sys2.c =updated sysfile
	
	syscall_64.tbl = old tablefile
	
	syscall_64.tbl = new tablefile
	
	
6. file details:
	table no:449
	SYSCALL_DEFINE4
	


