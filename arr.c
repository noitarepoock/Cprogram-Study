#include <stdio.h>
#include <string.h>

void swqp_ptr(char **ppa, char **ppb);
void print_str(char **pps, int cnt);

int main(void){
    // int score[3][4];
    // int total;
    // double avg;
    // int i, j;

    // for(i = 0; i < 3; i++){
    //     printf("4 subject score : ");
    //     for(j = 0; j < 4; j++){
    //         scanf("%d", &score[i][j]);
    //     }
    // }
    // // printf("%d", score[2][1]);

    // for(i = 0; i < 3; i++){
    //     total = 0;
    //     for(j = 0; j < 4; j++){
    //         total += score[i][j];
    //     }
    //     avg = total / 4.0;
    //     printf("total score : %d, avg : %.2lf\n", total, avg);
    // }



    // int num[3][4] = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12}
    // };

    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 4; j++){
    //         printf("%5d", num[i][j]);
    //     }
    //     printf("\n");
    // }

    // // int count = sizeof(num) / sizeof(num[0][0]);    printf("%d", count);


    
    // int score[2][3][4] ={
    //     {{72, 80, 95, 60}, {68, 98, 83, 90}, {75, 72, 84, 90}},
    //     {{66, 85, 90, 88}, {95, 92, 88, 95}, {43, 72, 56, 75}}
    // };

    // int i, j, k;

    // for(i = 0; i < 2; i++){
    //     printf("score of %d class...\n", i+1);
    //     for(j = 0; j < 3; j++){
    //         for(k = 0; k < 4; k++){
    //             printf("%5d", score[i][j][k]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }



    // char *pary[5];
    
    // pary[0] = "dog";
    // pary[1] = "elephant";
    // pary[2] = "horse";
    // pary[3] = "tiger";
    // pary[4] = "lion";

    // for(int i = 0; i < 5; i++){
    //     printf("%s\n", pary[i]);
    // }


    // int ary1[4] = {1, 2, 3, 4};
    // int ary2[4] = {11, 12, 13, 14};
    // int ary3[5] = {21, 22, 23, 24, 25};
    // int *pary[3] = {ary1, ary2, ary3};

    // for(int i = 0; i < 3; i++){
    //     for(int j = 0 ; j < 5; j++){
    //         printf("%5d", pary[i][j]);
    //     }
    //     printf("\n");
    // }



    // int ary[5][6] = {                                                                            //14-2 Q4 (도전 실전 예제)
    //     {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}
    // };

    // int last = 0;
    // for(int i = 0; i < 4; i++){
    //     int sum = 0;
    //     for(int j = 0; j < 5; j++){
    //         sum += ary[i][j];
    //         last += ary[i][j];
    //     }
    //     ary[i][5] = sum;
    // }
    // ary[4][5] = last;

    // for(int j = 0; j < 5; j++){
    //     int sum = 0;
    //     for(int i = 0; i < 4; i++){
    //         sum += ary[i][j];
    //     }
    //     ary[4][j] = sum;
    // }

    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 6; j++){
    //         printf("%5d", ary[i][j]);
    //     }
    //     printf("\n");
    // }




    // int a = 10;
    // int *pi;
    // int **ppi;

    // pi = &a;
    // ppi = &pi;

    // printf("--------------------------------------------\n");
    // printf("변수     변숫값     &연산     *연산     **연산\n");
    // printf("--------------------------------------------\n");
    // printf("    a%12d%12u\n", a, &a);
    // printf(" pi%12u%12u%12d\n",pi, &pi, *pi);
    // printf("ppi%12u%12u%12u%12u\n", ppi, &ppi, *ppi, **ppi);
    // printf("--------------------------------------------\n");



    // char *pa = "success";
    // char *pb = "failure";

    // printf("pa -> %s, pb -> %s\n", pa, pb);
    // swqp_ptr(&pa, &pb);

    // printf("pa -> %s, pb -> %s\n", pa, pb);




    // char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"};
    // int count;

    // count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
    // print_str(ptr_ary, count);

    // printf("%c", ptr_ary[0][0]);


    

    return 0;
}

void print_str(char **pps, int cnt){
    for(int i = 0; i < cnt; i++){
        printf("%s\n", pps[i]);
    }
}

void swqp_ptr(char **ppa, char **ppb){
    char *pt;
    pt = *ppa;
    *ppa = *ppb;
    *ppb = pt;
}

