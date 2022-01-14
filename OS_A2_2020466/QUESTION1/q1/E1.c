#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>



pid_t id;
void Signal_Handler(int signum){
    
    int n;
    asm ("rdrand %0": "=r"(n));

    union sigval abc;
    abc.sival_int=n;
    //calling function related to SIGTERM
    sigqueue(id,SIGTERM,abc);
    

}

int main(int argc,char * args[])
{
    pid_t id2=getpid();
    id=atoi(args[0]);
    printf("ID OF E1: %d\n",id2);
    struct sigaction act;
    struct sigaction o;

    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_handler = Signal_Handler;
    act.sa_flags=SA_RESTART;
    if(sigaction(SIGALRM,&act,&o)==-1){
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
        sleep(1);
    }

  
  }