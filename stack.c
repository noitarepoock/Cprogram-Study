#include <stdio.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

int IsEpt(){
    if(top < 0) return true;
    else return false;
}

int IsFull(){
    if(top >= MAX_STACK_SIZE) return true;
    else return false;
}

void push(int value){
    if(IsFull() == true){
        printf("stack FULL");
    }else{
        stack[++top] = value;
    }
}

int pop(){
    if(IsEpt() == true){
        printf("stack EMPTY");
    }else{
        return stack[top--];
    }
}

int main(void){

    push(3);
    push(5);
    push(12);

    printf("%5d\n", pop());
    printf("%5d\n", pop());
    printf("%5d\n", pop());
    printf("%5d\n", pop());

    return 0;
}