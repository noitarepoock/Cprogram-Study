#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void print_str(char **ps){
    while(*ps != NULL){
        printf("%s\n", *ps);
        ps++;
    }
}

// int IsPrime_Num(int num){
//     if(num <= 1) return 0;
//     if(num == 2) return 1;
//     for(int i = 2; i * i <= num; i++){
//         if(num % i == 0) return 0;
//     }
//     return 1;
// }


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 소수 판별 함수
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


   


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



    // int *pi;
    // int size = 5;
    // int count = 0;
    // int num;
    // int i;

    // pi = (int *)calloc(size, sizeof(int));      //5개의 저장 공간 할당
    // while(1){
    //     printf("양수 입력 => ");
    //     scanf("%d", &num);
    //     if(num <= 0) break;
    //     if(count == size){
    //         size += 5;
    //         pi = (int *)realloc(pi, size * sizeof(int));
    //     }
    //     pi[count++] = num;
    // }

    // printf("memory : %zu\n", sizeof(pi));
    // for(i = 0; i < count; i++){
    //     printf("%5d", pi[i]);
    // }
    // free(pi);


    // char tmp[80];
    // char *str[3];
    
    // for(int i = 0; i < 3; i++){
    //     printf("string : ");
    //     gets(tmp);
    //     str[i] = (char *)malloc(strlen(tmp) + 1);
    //     strcpy(str[i], tmp);
    // }
    // for(int i = 0; i < 3; i++){
    //     printf("%s\n", str[i]);
    // }
    // for(int i = 0 ; i < 3; i++){
    //     free(str[i]);
    // }




    // char tmp[80];
    // char *str[21] = {0};
    // int i;

    // while(i < 20){
    //     printf("string : ");
    //     gets(tmp);
    //     if(strcmp(tmp, "end") == 0) break;
    //     str[i] = (char *)malloc(strlen(tmp) + 1);
    //     strcpy(str[i], tmp);
    //     i++
    // }
    // print_str(str);

    // for(i = 0; str[i] != NULL i++){
    //     free(str[i]);
    // }



    // int num, row;                //16-2 Q4 (도전 실전 예제)
    
    // printf("양수 입력 : ");
    // scanf("%d", &num);
    // row = (num - 2 + 4) / 5;
    // int **matrix = (int **)malloc(sizeof(int *) * row);
    // if(matrix == NULL) {
    //     printf("error");
    //     exit(1);
    // }
    // for(int i = 0 ; i < row; i++){
    //     matrix[i] = (int *)malloc(sizeof(int) * 5);
    //     if(matrix[i] == NULL){
    //         printf("error2");
    //         exit(1);
    //     }
    // }
    // for(int i = 2; i < num; i++){
    //     if(IsPrime_Num(i) == 1){
    //         matrix[(i-2)/5][(i-2)%5] = i;
    //     }else{
    //         matrix[(i-2)/5][(i-2)%5] = 0;
    //     }
    // }
    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < 5; j++){
    //         if(matrix[i][j] != 0){
    //             printf("%5d", matrix[i][j]);
    //         }else if(matrix[i][j] == 0){
    //             printf("%5s", "X");
    //         }
    //     }
    //     printf("\n");
    // }

    // for(int i = 0; i < row; i++){
    //     free(matrix[i]);
    // }
    // free(matrix);
    


    // int num;                         GPT식,,, 도전 실전 예제
    // printf("양수를 입력하세요: ");
    // scanf("%d", &num);

    // // 동적 메모리 할당
    // int *arr = (int *)malloc((num + 1) * sizeof(int));
    // if (arr == NULL) {
    //     printf("메모리 할당 실패!\n");
    //     return 1;
    // }

    // // 소수 여부를 배열에 저장
    // for (int i = 0; i <= num; i++) {
    //     if (is_prime(i)) {
    //         arr[i] = i;  // 소수이면 그 수 저장
    //     } else {
    //         arr[i] = -1; // 소수가 아니면 -1로 표시
    //     }
    // }

    // // 배열 출력
    // int count = 0;
    // for (int i = 2; i < num; i++) {
    //     if (arr[i] != -1) {
    //         printf("%5d", arr[i]);
    //     } else {
    //         printf("    X");
    //     }
        
    //     count++;
    //     if (count % 5 == 0) {
    //         printf("\n");
    //     }
    // }
    // printf("\n");
    // // 메모리 해제
    // free(arr);

    
    return 0;
}
