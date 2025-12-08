/****************************************************************************************************************************************/
/*                                                             Array Stack                                                              */
/****************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType Data;
}Node;

typedef struct tagArrayStack{
    int Capacity;
    int Top;
    Node *Nodes;
}ArrayStack;

void AS_CreateStack(ArrayStack **Stack, int Capacity){
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    (*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack *Stack){
    free(Stack->Nodes);

    free(Stack);
}

void AS_Push(ArrayStack *Stack, ElementType Data){
    Stack->Top++;
    Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack *Stack){
    int Position = Stack->Top--;
    return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack *Stack){
    return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack *Stack){
    return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack *Stack){
    return (Stack->Top == -1);
}

bool AS_Full(ArrayStack *Stack){
    return (Stack->Capacity == Stack->Top+1);
}

int main(void){
    int i = 0;
    ArrayStack *Stack = NULL;

    AS_CreateStack(&Stack, 10);

    AS_Push(Stack, 3);
    AS_Push(Stack, 37);
    AS_Push(Stack, 11);
    AS_Push(Stack, 12);

    printf("Capacity : %d, Size : %d, Top : %d\n\n",
            Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

    for(i = 0; i < 4; i++){
        if(AS_IsEmpty(Stack)) break;

        printf("Popped : %d, ", AS_Pop(Stack));

        if(!AS_IsEmpty(Stack)) printf("Current Top : %d\n", AS_Top(Stack));
        else printf("Stack Is Empty");
    }

    AS_DestroyStack(Stack);

    return 0;
}