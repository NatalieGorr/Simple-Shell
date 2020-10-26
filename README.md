# OSlab1

Natalie Gorr
October 26, 2020

 This program creates a simple "Shell"
 It has three built-in commands:printid, exit, and greet
 It aslo has ls, pwd, ps, date, lscpu which are exectuted by forking
 the current process and using execve()

 printid - prints current process id number
 exit - terminates the progtam
 greet - prints "Hello"
 ls - lists the files in the current directory
 pwd - prints the path of the current working directory
 ps - prints the status of the current processes
 date - prints current date and time
 lscpu - prints information about the current processes of the machine