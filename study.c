#include <stdio.h>
#include <string.h>

char *my_strcpy(char *pd, char *ps);

int main(){
    /*
    char str1[80] = "strawberry";
    char str2[80] = "apple";
    char *ps1 = "banana";
    char *ps2 = str2;

    printf("first string : %s\n", str1);
    strcpy(str1, str2);
    printf("changing string : %s\n", str1);

    strcpy(str1, ps1);
    printf("changing string : %s\n", str1);

    strcpy(str1, "melon");
    printf("changing string : %s\n", str1); //복사 후 사용

    
    */  //strcpy(char *ps1, char *ps2)

    /*
    char str[20] = "mango tree";

    strncpy(str, "apple-pie", 5);

    printf("%s\n", str);
    */  //strncpy(char *ps1, char *ps2, num)

    /*

    char str[80] = "straw";

    strcat(str, "berry");
    printf("%s\n", str);
    strncat(str, "piece", 3);
    printf("%s\n", str);

    */  //strcat, strncat

    /*

    char str1[80], str2[80];
    char *resp;

    printf("2fruits name : ");
    scanf("%s %s", str1, str2);
    resp = strlen(str1) > strlen(str2) ? str1 : str2;

    printf("long name fruits : %s", resp);

    */  //strlen

    /*
    char str1[80] = "pear";
    char str2[80] = "peach";

    printf("late fruits in dictionary : %s", strcmp(str1, str2) > 0 ? str1 : str2);
    */  //strcmp string compare


    /*
    char str[80] = "strawberry";

    printf("origin string : %s\n", str);
    my_strcpy(str, "apple");
    printf("changing string : %s\n", str);
    printf("another string : %s", my_strcpy(str, "kiwi"));
    */          //strcpy와 같은 기능을 하는 함수 직접 만들기

    return 0;
}

char *my_strcpy(char *pd, char *ps){
    char *po = pd;

    while(*ps != '\0'){
        *pd = *ps;
        pd++;
        ps++;
    }

    *pd = '\0';

    return po;
}
