#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    FILE *fp;       //file pointer

    fp = fopen("a.txt", "r");
    if(fp == NULL){
        printf("file not opened\n");
        return 1;
    }
    printf("file opened\n");
    fclose(fp);

    return 0;
}