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



    int num[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%5d", num[i][j]);
        }
        printf("\n");
    }

    return 0;
}