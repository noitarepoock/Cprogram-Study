#include <stdio.h>
#include <string.h>

int main(void){
    int time;
    double points = 0;
    double originE = 0.25;          //workship, saddle, memorial
    double moveE = 0.5;             //moveEvent only

    printf("times of originE : ");
    scanf("%d", &time);

    points += originE * time;

    // printf("%.2lf", points);

    printf("times of moveE : ");
    scanf("%d", &time);

    points += moveE * time;
    points += (int)points / 9;      //상점이 9점이 되면 추가로 1점을 더 받는다.

    printf("%.2lf", points);

    return 0;
}