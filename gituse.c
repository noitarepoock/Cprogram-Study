#include <stdio.h>

int main() {
    char str[80] = "apple juice";
    char *ps = "banana";

    puts(str);
    fputs(ps, stdout);
    printf("\n");
    puts("milk");

    return 0;
}
