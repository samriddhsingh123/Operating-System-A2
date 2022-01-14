#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
long randomn(int var){

    return var;
}
void Signal_Handler(int signum, siginfo_t *info, void *context){
    printf ("Random No: %d\n",info->si_value.sival_int);
}

int id=0;
int  main(){
    pid_t pid;
    pid=fork();
    if(pid==0){
        
        id=getpid();
        struct sigaction act;
        struct sigaction o;


        // sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
        act.sa_sigaction = &Signal_Handler;
        act.sa_flags=SA_SIGINFO;

        //when sigterm will come then this function will be called 
        if(sigaction(SIGTERM, &act, &o)==-1){
            perror("Sigaction");
            exit(0);
  }
        printf("ID OF S1: %d\n",getpid());
        while(1){
        
        
        sleep(1);
        }
       
        
}



else if(pid>0){

    pid_t pid1;
    pid1=fork();
    if(pid1==0){
        
        char arr[15];
        sprintf(arr,"%d",pid);
        
        
        execl("E1",arr,NULL);
        //sr


    }
    else if(pid1>0){
        pid_t pid2;

        pid2=fork();
        if(pid2==0){
        //st
        char arr2[15];
        sprintf(arr2,"%d",pid);
        
        // sprintf(arr,"%d",id);
        
        execl("E2",arr2,NULL);
        }
        else if(pid2>0){

        }
        else{
            printf("forking failed");
        }
    }
    else{
        printf("forking failed");
    }
}
else{
    printf("forking failed");
}
}