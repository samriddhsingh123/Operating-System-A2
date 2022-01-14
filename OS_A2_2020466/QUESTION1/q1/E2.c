#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <math.h>

pid_t id;

void Signal_Handler(int signum){
    int num;
    long x,y;
    asm ("rdrand %0": "=r"(num));
    union sigval abc;
    abc.sival_int=num;
    //calling function related to SIGTERM
    sigqueue(id,SIGTERM,abc);
    asm("rdtsc": "=a"(x),"=d"(y));
    long long n=(pow(2,32)*y + x)/(2112000000);
    
    
    int day = n / (24 * 60 * 60);
 
    n = n % (24 * 3600);
    int hour = n / 3600;
 
    n %= 3600;
    int minutes = n / 60 ;
 
    n %= 60;
    int seconds = n;
    
    char ab[100];
    sprintf(ab,"days: %d  hrs:%d  mins:%d seconds:%d  \n",day, hour,minutes,seconds);
    abc.sival_ptr=ab;
    sigqueue(getpid(),SIGTERM,abc);
    
    
    
}
void handler(int signum, siginfo_t *info, void *context){
    printf ("%s\n",info->si_value.sival_ptr);
}

int main(int argc,char * args[])
{

    id=atoi(args[0]);
    pid_t id2=getpid();
    printf("ID OF E2: %d\n",id2);
    
    struct sigaction act;
    struct sigaction xy;
    struct sigaction o;
    struct sigaction yz;


    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_handler = Signal_Handler;
    act.sa_flags=SA_RESTART;

    if(sigaction(SIGALRM,&act,&o)==-1){
        perror("Sigaction");
        exit(0);
    }

    // act.sa_handler=handler; 
    xy.sa_flags = 0;
    xy.sa_sigaction = &handler;
    xy.sa_flags=SA_SIGINFO;
    if(sigaction(SIGTERM,&xy,&yz)==-1){
        perror("Sigaction");
        exit(0);
    }

    struct itimerval tim;
    tim.it_value.tv_sec = 5; 
    tim.it_value.tv_usec = 0; 
    tim.it_interval.tv_sec = 5; 
    tim.it_interval.tv_usec = 0; 
    if (setitimer(ITIMER_REAL, &tim, NULL) == -1) {
                perror("setitimer()");
                exit(1);
            }
    while (1)
    {
        // sleep(1);
    }
    

  
  }