/****************************************************************************************************************************************/
/*                                                             bSearch                                                                  */
/****************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "QsortPoint.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//C언어 표준 라이브러리의 이진 탐색 함수 : bsearch()
// void *bsearch(const void *key, const void *base, size_t num, size_t width, int(__cdec1 *compare)(const void *, const void *));

int ComparePoint(const void *_elem1, const void *_elem2){
    Point *elem1 = (Point*)_elem1;
    Point *elem2 = (Point*)_elem2;

    if(elem1->point > elem2->point) return 1;
    else if(elem1->point < elem2->point) return -1;
    else return 0;
}

int main(void){
    int Lnth = sizeof DataSet / sizeof DataSet[0];
    Point Target;
    Point *Found = NULL;

    qsort((void *)DataSet, Lnth, sizeof(Point), ComparePoint);

    Target.id = 0;
    Target.point = 671.78;

    Found = bsearch((void*)&Target,
                    (void*)DataSet,
                    Lnth,
                    sizeof(Point),
                    ComparePoint);

    printf("Found ... ID : %d, Point :%f\n", Found->id, Found->point);

    return 0;
}