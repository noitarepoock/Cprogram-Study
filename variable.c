#include <stdio.h>
#include <string.h>

void assign(void);

int main() {
    // auto int a = 20;        //in main function variable a

    // assign();
    // printf("main function a : %d\n", a);


    int a = 10, b = 20;

    printf("before exchanging a, b : %d %d\n", a ,b);
    {
        int tmp;                //Can use only in this block

        tmp = a;
        a = b;
        b = tmp;
    }
    printf("after exchanging a, b : %d %d\n", a, b);
    //printf("tmp : %d", tmp);

    return 0;
}

void assign(void){
    int a;      //in assign function varialbe a

    a = 10;
    printf("assign function a : %d\n", a);
}