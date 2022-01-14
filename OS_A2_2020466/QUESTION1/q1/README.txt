Process to compile the code: 
		make
then type      : ./a

1.In the q1.c the parent process forks processes S1, SR, and ST.
Once the SR or ST function are forked corresponding E1 and E2 program are called using execl command.
1. we used this to send the pid of S1 to the program E1 and E2 as command line arguement.
2. SR and ST both registers handler function for SIGALRM signal. Both the handler function generates
a random value to be sent to S1.
3. RDRAND used to generate random numbers. E1 program also registers function handler for SIGTERM signal,
which is used to print the string passed to it. The SIGALRM
signal handler function of this program also uses RDTSC instruction to approximate the time
since last reset of cpu.
4. RDTSC instruction gives the number of cycles cpu run after the last reset.
eax and edx registers stored this information, where edx stores higher 32 bits, and eax stores lower 32 bits.
timer for SIGALRM signal are set to 5 seconds for E1 and E2 resp.
5. We use this timestamp and convert it into days, hours, minutes and seconds using simple mathematics

OUTPUT:
 Then random number is generated and printed from signal handler in S1.
 Then the timestamp is printed giving the time the cpu is running from.
To stop execution:	
	kill the process process susing the command in the other terminal as: kill -9 pidValueWhichisPrintedAtTheStart
