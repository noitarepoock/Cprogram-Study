#include <stdio.h>
#include <string.h>

void assign(void);
void assign10(void);
void assign20(void);
void auto_func(void);
void static_func(void);
int add_ten(int a);
void add_r_ten(int *pa);            //addByAddress
int *sum(int a, int b);
void input_data(int *pa, int *pb);
void swap_data(void);
void print_data(int a, int b);

// int a;          //global variable a

// int a, b;        //13-2 Q4(도전 실전 예제)

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


    // register int i;         //store variable in register in CPU
    // int sum = 0;

    // for(i = 1; i <= 10000; i++){
    //     sum += i;
    // }

    // printf("%d\n", sum);


    // int a = 10;

    // // add_ten(a);             //copy a to add_ten function
    // printf("a : %d\n", add_ten(a));


    // int a = 10;

    // add_r_ten(&a);
    // printf("a : %d\n", a);

    // int *resp;

    // resp = sum(10, 20);             //resp = &res in *sum function
    // printf(" adding two num : %d", *resp);



    // input_data(&a, &b);          //13-2 Q4(도전 실전 예제)
    // swap_data();
    // print_data(a, b);

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

int add_ten(int a){
    a = a + 10;

    return a;
}

void add_r_ten(int *pa){
    *pa += 10;
}

int *sum(int a, int b){
    static int res;
    
    res = a + b;

    return &res;
}

void input_data(int *pa, int *pb){

    printf("input two num : ");
    scanf("%d %d", pa, pb);
}
void swap_data(void){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void print_data(int a, int b){
    printf("output two num : %d, %d\n",a, b);
}