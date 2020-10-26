/*
 * This program creates a simple "Shell"
 * It has three built-in commands:printid, exit, and greet
 * It aslo has ls, pwd, ps, date, lscpu which are exectuted by forking
 * the current process and using execve()
 *
 * printid - prints current process id number
 * exit - terminates the progtam
 * greet - prints "Hello"
 * ls - lists the files in the current directory
 * pwd - prints the path of the current working directory
 * ps - prints the status of the current processes
 * date - prints current date and time
 * lscpu - prints information about the current processes of the machine
 *
 * author: Natalie Gorr
 * date: October 27, 2020
 */




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>


// declare functions printid() and greet()
void printid();
void greet();


int main(){


    while(1){

        printf("lab1> ");

        //get user input for which command to execute in the current loop
        char input[50];
        if(scanf("%s",input) == 0){
           exit(0);
        }
        //initialize the first part of the "complete command string"
        char commandstart[50] = "/bin/";

        printf("Parent Process %d\n", getpid());

        //check if the user input is any of the three built-in commands,
        // if so execute them
        if ( strcmp(input,"exit") == 0  ){
            exit(0);
        }

        else if ( strcmp(input,"printid") == 0  ){
            printid();
        }

        else if ( strcmp(input,"greet") == 0  ){
            greet();
        }

        //else command is is one which needs to use fork, or it is not a supported command
        else{

            //concatenate the user input with the "command starter" string
            strcat(commandstart, input);

            //use this so the parent waits for the child
            int child_status;

            pid_t pid = fork();
            if( pid == 0 ) {
               printf("Child process %d will execute the command %s\n", getpid(), input );

               // use execve to execue command
                char * argv[]= {input, NULL};
                execve(commandstart, argv, NULL);

                printf("Command Not Found!\n");
                exit(0);
            }
            //end of waiting
            wait(&child_status);
        }
    }
    return 0;
}


//function prints the current process id number
void printid(){
    printf("The ID of the current process is  %d\n", getpid());
}
//function prinyts hello
void greet(){
    printf("Hello\n");

}