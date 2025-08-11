#include <stdio.h>
#include <string.h>

void assign(void);

int main() {
    // auto int a = 20;        //in main function variable a

    // assign();
    // printf("main function a : %d\n", a);


    

    return 0;
}

void assign(void){
    int a;      //in assign function varialbe a

    a = 10;
    printf("assign function a : %d\n", a);
}