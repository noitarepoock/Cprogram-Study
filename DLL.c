/****************************************************************************************************************************************/
/*                                                            Doubly Linked List                                                        */
/****************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType data;
    struct tagNode *PrevNode;
    struct tagNode *NextNode;
}Node;

Node *DLL_CreateNode(ElementType NewData){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    
    NewNode->data = NewData;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;
}

void DLL_DestroyNode(Node *Node){
    free(Node);
}

void DLL_AppendNode(Node **Head, Node *NewNode){
    if((*Head) == NULL){
        (*Head) = NewNode;
    }else{
        Node *Tail = (*Head);
        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

Node *DLL_GetNodeAt(Node *Head, int Location){
    Node *Current = Head;

    while(Head != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }
    return Current;
}