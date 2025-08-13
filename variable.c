#include <stdio.h>
#include <string.h>

void assign(void);
void assign10(void);
void assign20(void);
void auto_func(void);
void static_func(void);

// int a;          //global variable a

int main() {
    // auto int a = 20;        //in main function variable a

    // assign();
    // printf("main function a : %d\n", a);


    // int a = 10, b = 20;

    // printf("before exchanging a, b : %d %d\n", a ,b);
    // {
    //     int tmp;                //Can use only in this block

    //     tmp = a;
    //     a = b;
    //     b = tmp;
    // }
    // printf("after exchanging a, b : %d %d\n", a, b);
    // //printf("tmp : %d", tmp);



    // printf("before call function a : %d\n", a);

    // assign20();
    // assign10();

    // printf("after calling function a : %d\n", a);


    
    // int i;

    // printf("using auto function\n");
    // for(i = 0; i < 3; i++){
    //     auto_func();
    // }

    // printf("using static function\n");
    // for(i = 0; i < 3; i++){
    //     static_func();
    // }


    register int i;         //store variable in register in CPU
    int sum = 0;

    for(i = 1; i <= 10000; i++){
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}

void assign(void){
    int a;      //in assign function varialbe a

    a = 10;
    printf("assign function a : %d\n", a);
}

// void assign10(void){
//     a = 10;
// }
void assign20(void)
{
    int a;     //local variable a can use only in this function

    a = 20;
}

void auto_func(void){
    auto int a = 0;

    a++;
    printf("%d\n", a);
}

void static_func(void){
    static int a;

    a++;
    printf("%d\n", a);
}