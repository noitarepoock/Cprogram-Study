/****************************************************************************************************************************************/
/*                                                       Linked List Stack                                                              */
/****************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct tagNode{
    char *Data;
    struct tagNode *NextNode;
}Node;

typedef struct tagLinkedListStack{
    Node *List;
    Node *Top; //Tail
}LinkedListStack;

void LLS_CreateStack(LinkedListStack **Stack){
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

Node *LLS_CreateNode(char *NewData){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->Data = (char *)malloc(sizeof(char));

    strcpy(NewNode->Data, NewData);

    NewNode->NextNode = NULL;

    return NewNode;
}

void LLS_DestroyNode(Node *node){
    free(node->Data);
    free(node);
}

int LLS_IsEmpty(LinkedListStack *Stack){
    return Stack->List == NULL;
}

Node *LLS_Pop(LinkedListStack *Stack){
    Node *TopNode = Stack->Top;
    
    if(Stack->List == Stack->Top){
        Stack->List = NULL;
        Stack->Top = NULL;
    }else{
        Node *CurrentTop = Stack->List;
        while(CurrentTop != NULL && CurrentTop->NextNode != Stack->Top){
            CurrentTop = CurrentTop->NextNode;
        }

        Stack->Top = CurrentTop;
        Stack->Top->NextNode = NULL;
    }
    return TopNode;
}

void LLS_DestroyStack(LinkedListStack *Stack){
    while(!LLS_IsEmpty(Stack)){
        Node *Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }
    free(Stack);
}

void LLS_Push(LinkedListStack *Stack, Node *NewNode){
    if(Stack->List == NULL){
        Stack->List = NewNode;
    }else{
        Stack->Top->NextNode = NewNode;
    }

    Stack->Top = NewNode;
}

Node *LLS_Top(LinkedListStack *Stack){
    return Stack->Top;
}

int LLS_GetSize(LinkedListStack *Stack){
    int Count = 0;
    Node *Current = Stack->List;

    while(Current != NULL){
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

// int LLS_IsEmpty(LinkedListStack *Stack){
//     return Stack->List == NULL;
// }

int main(void){
    int i = 0;
    int Count = 0;
    Node *Popped;
    LinkedListStack *Stack = NULL;

    LLS_CreateStack(&Stack);

    LLS_Push(Stack, LLS_CreateNode("abc"));
    LLS_Push(Stack, LLS_CreateNode("def"));
    LLS_Push(Stack, LLS_CreateNode("ghi"));
    LLS_Push(Stack, LLS_CreateNode("jkl"));

    Count = LLS_GetSize(Stack);
    printf("Size : %d, Top : %s\n\n",
            Count, LLS_Top(Stack)->Data);

    for(i = 0; i < Count; i++){
        if(LLS_IsEmpty(Stack)) break;

        Popped = LLS_Pop(Stack);
        printf("Popped : %s, ", Popped->Data );

        if(!LLS_IsEmpty(Stack)) printf("Current Top : %s\n", LLS_Top(Stack)->Data);
        else printf("Stack Is Empty");
    }

    LLS_DestroyStack(Stack);

    return 0;
}