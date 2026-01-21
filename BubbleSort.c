/****************************************************************************************************************************************/
/*                                                            Bubble Sort                                                               */
/****************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void BubbleSort(int DataSet[], int Length){
    int i = 0;
    int j = 0;
    int tmp = 0;
    bool swapped;

    for(i = 0; i < Length - 1; i++){
        swapped = false;

        for(j = 0; j < Length-(i+1); j++){
            if(DataSet[j] > DataSet[j+1]){
                tmp = DataSet[j];
                DataSet[j] = DataSet[j+1];
                DataSet[j+1] = tmp;
            }
        }

        if(!swapped) break;
    }
}

int main(void){
    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    BubbleSort(DataSet, Length);

    for(i = 0; i < Length; i++){
        printf("%d ",DataSet[i]);
    }

    printf("\n");

    return 0;
}