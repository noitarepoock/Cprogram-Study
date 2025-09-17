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



    // int ch;

    // while(1){
    //     ch = fgetc(stdin);
    //     if(ch == EOF){
    //         break;
    //     }
    //     fputc(ch, stdout);
    // }



    // FILE *fp;
    // int ary[10] = {13, 10, 13, 13, 10, 26, 13, 10, 13, 10};
    // int res;

    // fp = fopen("a.txt", "wb");
    // for(int i = 0; i < 10; i++){
    //     fputc(ary[i], fp);
    // }
    // fclose(fp);

    // fp = fopen("a.txt", "rt");
    // while(1){
    //     res = fgetc(fp);
    //     if (res == EOF) break;
    //     printf("%4d", res);
    // }
    // fclose(fp);



    // FILE *fp;
    // char str[20];

    // fp = fopen("a.txt", "a+");
    // if(fp == NULL){
    //     printf("file NOT maken");
    //     return 1;
    // }

    // while(1){
    //     printf("fruits : ");
    //     scanf("%s", str);
    //     if(strcmp(str, "end") == 0){
    //         break;
    //     }
    //     else if(strcmp(str, "list") == 0){
    //         fseek(fp, 0, SEEK_SET);                 //버퍼의 위치 지시자를 맨 앞으로 이동
    //         while(1){
    //             fgets(str, sizeof(str), fp);        //과일 이름을 읽는다.
    //             if(feof(fp)){                       //파일의 내용을 모두 읽으면 종료
    //                 break;
    //             }
    //             printf("%s", str);
    //         }
    //     }
    //     else{
    //         fprintf(fp, "%s\n", str);
    //     }
    // }
    // fclose(fp);



    // FILE *ifp, *ofp;
    // char str[80];
    // char *res;

    // ifp = fopen("a.txt", "r");
    // if(ifp == NULL){
    //     printf("file not opened");
    //     return 1;
    // }

    // ofp = fopen("b.txt", "w");
    // if(ofp == NULL){
    //     printf("file not opened");
    //     return 1;
    // }

    // while(1){
    //     res = fgets(str, sizeof(str), ifp);
    //     if(res == NULL){
    //         break;
    //     }
    //     str[strlen(str) - 1] = '\0'; //개행 문자 제거
    //     fputs(str, ofp);
    //     fputs(" ", ofp);
    // }

    // fclose(ifp);
    // fclose(ofp);




    // FILE *ifp, *ofp;
    // char name[20];
    // int kor, eng, math;
    // int total;
    // double avg;
    // int res;

    // ifp = fopen("a.txt", "r");
    // if(ifp == NULL){
    //     printf("not file opened");
    //     return 1;
    // }

    // ofp = fopen("b.txt", "w");
    // if(ofp == NULL){
    //     printf("not file opened");
    //     return 1;
    // }

    // while(1){
    //     res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
    //     if(res == EOF){
    //         break;
    //     }
    //     total = kor + eng + math;
    //     avg = total / 3.0;
    //     fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
    // }

    // fclose(ifp);
    // fclose(ofp);



    FILE *fp;
    int age;
    char name[20];

    fp = fopen("a.txt", "r");

    fscanf(fp, "%d", &age);
    fgetc(fp);              // /r
    fgetc(fp);              // /n
    fgets(name, sizeof(name), fp);

    printf("age : %d, name : %s", age, name);
    fclose(fp);

    return 0;
}