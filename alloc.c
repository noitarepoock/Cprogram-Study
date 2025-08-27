#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    // int *pi;
    // double *pd;

    // pi = (int *)malloc(sizeof(int));
    // if(pi == NULL){
    //     printf("# Not Memory");
    //     exit(1);
    // }
    // pd = (double *)malloc(sizeof(double));

    // *pi = 10;
    // *pd = 3.4;

    // printf("int : %d\n", *pi);
    // printf("double : %.1lf\n", *pd);

    // free(pi);
    // free(pd);


    // int *pi;
    // int sum = 0;

    // pi = (int *)malloc(sizeof(int) * 5);        //using for ary
    // if(pi == NULL){
    //     printf("Not Memory\n");
    //     exit(1);
    // }
    // printf("input 5 person's age : ");
    // for(int i = 0; i < 5; i++){
    //     scanf("%d", &pi[i]);
    //     sum += pi[i];
    // }

    // printf("average of 5 p's age : %.1lf\n", (sum / 5.0));
    // free(pi);



    int *pi;
    int size = 5;
    int count = 0;
    int num;
    int i;

    pi = (int *)calloc(size, sizeof(int));      //5개의 저장 공간 할당
    while(1){
        printf("양수 입력 => ");
        scanf("%d", &num);
        if(num <= 0) break;
        if(count == size){
            size += 5;
            pi = (int *)realloc(pi, size * sizeof(int));
        }
        pi[count++] = num;
    }

    printf("memory : %zu\n", sizeof(pi));
    for(i = 0; i < count; i++){
        printf("%5d", pi[i]);
    }
    free(pi);

    return 0;
}