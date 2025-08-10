#include <stdio.h>

int main(){
    int i = 0;
    char str[20];
    char ch;

    do{
        ch = getchar();
        str[i] = ch;
        i++;
    }while(ch != '\n');

    str[--i] == '\0'; //개행 문자 제거

    printf("%s", str);
    return 0;
}
