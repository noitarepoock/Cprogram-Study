#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    // FILE *fp;       //file pointer

    // fp = fopen("a.txt", "r");
    // if(fp == NULL){
    //     printf("file not opened\n");
    //     return 1;
    // }
    // printf("file opened\n");
    // fclose(fp);


    // FILE *fp;                //fgetc function
    // int ch;

    // fp = fopen("a.txt", "r");
    // if(fp == NULL){
    //     printf("fileNotOpened\n");
    //     return 1;
    // }

    // while(1){
    //     ch = fgetc(fp);
    //     if(ch == EOF){
    //         break;
    //     }
    //     putchar(ch);
    // }
    // fclose(fp);



    // FILE *fp;
    // char str[] = "banana";
    // int i;

    // fp = fopen("b.txt", "w");
    // if(fp == NULL){
    //     printf("fileCANNOTmaken\n");
    //     return 1;
    // }

    // i = 0;
    // while(str[i] != '\0'){
    //     fputc(str[i], fp);
    //     i++;
    // }
    // fputc('\n', fp);
    // fclose(fp);



    // int ch;

    // while(1){
    //     ch = getchar();
    //     if(ch == EOF){
    //         break;
    //     }
    //     putchar(ch);
    // }



    int ch;

    while(1){
        ch = fgetc(stdin);
        if(ch == EOF){
            break;
        }
        fputc(ch, stdout);
    }

    return 0;
}