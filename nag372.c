/*
 * This program creates a simple "Shell"
 *
 * author: Natalie Gorr
 * date: May 6, 2020
 *
 */




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>



void printid();
void greet();


int main(){


    while(1){
        printf("lab1> ");

        char input[50];

        char commandstart[50] = "/bin/";

        //if(fgets(input,50,stdin) == NULL){
        //    exit(0);
        //}

       if(scanf("%s",input) == 0){
           exit(0);
       }



       printf("Parent Process %d\n", getpid());



        if ( strcmp(input,"exit") == 0  ){
            exit(0);
       }

        if ( strcmp(input,"printid") == 0  ){
            printid();
       }

       if ( strcmp(input,"greet") == 0  ){
            greet();
       }


        else{

            strcat(commandstart, input);

            int child_status;

            pid_t pid = fork();
            if( pid == 0 ) {
               printf("Child process %d will execute the command %s\n", getpid(), input );

               char * argv[]= {input, NULL};


                execve(commandstart, argv, NULL);


                printf("Command Not Found!\n");
                exit(0);
            }
            wait(&child_status);
        }
    }
    return 0;
}



void printid(){
    printf("The ID of the current process is  %d\n", getpid());
}

void greet(){
    printf("Hello\n");

}