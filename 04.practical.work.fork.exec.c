#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>

int main() {
    int pid=fork();

    if (pid!=0) {
        printf("I am the parent, my first child's id is %d\n",pid);
        wait(NULL);
        printf("Finish with 1st child process\n");
        pid=fork();

        if (pid!=0) {
            printf("I am still the parent, my secound child's id is %d\n",pid);
            wait(NULL);
            printf("Finish with 2nd child process\n");
        }

        else if (pid==0) {
            printf("I am the second child of my parent, running ps -ef\n");
            char *arg[] = {"/bin/ps", "-ef", NULL};
            execvp(arg[0],arg);
        }
    }

    else if (pid==0) {
        printf("I am the first child of my parent, running free -h\n");
        char *arg[]={"/usr/bin/free","-h",NULL};
        execvp(arg[0],arg);
    }
}