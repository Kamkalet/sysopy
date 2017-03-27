#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int i = 0;
    pid_t pid1, pid2, pid3;
    pid1=0, pid2=0, pid3=0;
    pid1 = fork();
    if ( pid1 < 0 ) printf("failed to fork");
    if ( pid1 == 0 ) {
    // jestesmy w procesie macierzystym
        pid2 = fork();
        pid3 = fork();

    }
    else {
        if(pid3==0){
            pid2=fork();
        }
        pid3 = fork();
        if((pid1==0)&&(pid2 == 0)){
            printf("Level 1\n");
        }
        if(pid1!=0){
            printf("Level 2\n");
        }
        if(pid2!=0){
            printf("Level 3\n");
        }
        if(pid3!=0){
            printf("Level 4\n");
        }


    }

    return 0;
}
