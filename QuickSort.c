/****************************************************************************************************************************************/
/*                                                            Quick Sort                                                                */
/****************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void Swap(int *A, int *B){
    int tmp = *A;
    *A = *B;
    *B = tmp;
}

int Partition(int DataSet[], int Left, int Right){
    int First = Left;
    int Pivot = DataSet[First];

    ++Left;

    while(Left <= Right){
        while(DataSet[Left] <= Pivot && Left < Right) ++Left;

        while(DataSet[Right] >= Pivot && Left <= Right) --Right;
        
        if(Left < Right) Swap(&DataSet[Left], &DataSet[Right]);
        else break;
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;   //Location of Pivot
}

void QuickSort(int DataSet[], int Left, int Right){
    if(Left < Right){
        int Idx = Partition(DataSet, Left, Right);      //Location of Pivot

        QuickSort(DataSet, Left, Idx-1);
        QuickSort(DataSet, Idx + 1, Right);
    }
}

int ComparePoint(const void *_elem1, const void *_elem2){
    int *elem1 = (int*)_elem1;
    int *elem2 = (int*)_elem2;

    if(*elem1 > *elem2) return 1;
    else if(*elem1 < *elem2) return -1;
    else return 0;
}

int ComparePointDescend(const void *_elem1, const void *_elem2){
    int *elem1 = (int*)_elem1;
    int *elem2 = (int*)_elem2;

    if(*elem1 < *elem2) return 1;
    else if(*elem1 > *elem2) return -1;
    else return 0;
}

int main(void){
    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    qsort((void*)DataSet, Length, sizeof(int), ComparePointDescend);

    for(i = 0; i < Length; i++)
        printf("%d ",DataSet[i]);
    printf("\n");
    return 0;
}

// int main(void){
//     int DataSet[] = {6, 4, 2, 3, 1, 5};
//     int Length = sizeof DataSet / sizeof DataSet[0];
//     int i = 0;

//     QuickSort(DataSet, 0, Length - 1);

//     for(i = 0; i < Length; i++) printf("%d ",DataSet[i]);
//     printf("\n");

//     return 0;
// }