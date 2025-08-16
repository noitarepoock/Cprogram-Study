#include <stdio.h>
#include <string.h>

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


    int ary1[4] = {1, 2, 3, 4};
    int ary2[4] = {11, 12, 13, 14};
    int ary3[5] = {21, 22, 23, 24, 25};
    int *pary[3] = {ary1, ary2, ary3};

    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 5; j++){
            printf("%5d", pary[i][j]);
        }
        printf("\n");
    }

    return 0;
}