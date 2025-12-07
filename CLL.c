/****************************************************************************************************************************************/
/*                                          Circular Linked List(BASED BY DOUBLY LINKED LIST)                                           */
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

Node *CLL_CreateNode(ElementType NewData){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    
    NewNode->data = NewData;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;
}

void CLL_DestroyNode(Node *Node){
    free(Node);
}

void CLL_AppendNode(Node **Head, Node *NewNode){
    if((*Head) == NULL){
        (*Head) = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else{
        Node *Tail = (*Head)->PrevNode;

        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;

        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail;
    }
}

void CLL_InsertNode(Node *Current, Node *NewNode){
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if(Current->NextNode != NULL){
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

void CLL_RemoveNode(Node **Head, Node *Remove){
    if((*Head) == Remove){
        (*Head)->PrevNode->NextNode = Remove->NextNode;
        (*Head)->NextNode->PrevNode = Remove->PrevNode;

        *Head = Remove->NextNode;

        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }else{
        Remove->NextNode->PrevNode = Remove->PrevNode;
        Remove->PrevNode->NextNode = Remove->NextNode;

        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }
}

Node *CLL_GetNodeAt(Node *Head, int Location){
    Node *Current = Head;

    while(Head != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }
    return Current;
}

int CLL_GetNodeCount(Node *Head){
    unsigned int Count = 0;
    Node *Current = Head;

    while(Current != NULL){
        Current = Current->NextNode;
        Count++;
        
        if(Current == Head) break;
    }

    return Count;
}

void PrintNode(Node *Node){
    if(Node->NextNode == NULL){
        printf("Prev : NULL\n");
    }else{
        printf("Prev : %d\n", Node->PrevNode->data);
    }
    printf("Current : %d\n", Node->data);

    if(Node->NextNode == NULL){
        printf("Next : NULL\n");
    }else{
        printf("Next : %d\n", Node->NextNode->data);
    }
}

void PrintReverse(Node *Head){

    int Count = CLL_GetNodeCount(Head);

    Node *Current = CLL_GetNodeAt(Head, Count-1);
    for(int i = Count-1; i >= 0; i--){
        printf("List[%d] : %d\n", i, Current->data);
        Current = Current->PrevNode;
    }
}

int main(void){
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *NewNode = NULL;
    Node *Current = NULL;

    //Add 5Nodes
    for(i = 0; i < 5; i++){
        NewNode = CLL_CreateNode(i);
        CLL_AppendNode(&List, NewNode);
    }

    //Print List
    Count = CLL_GetNodeCount(List);
    for(i = 0; i < Count; i++){
        Current = CLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->data);
    }

    //Add Node After 3rd Node
    printf("\nInserting 3000 After [2]...\n");

    Current = CLL_GetNodeAt(List, 2);
    NewNode = CLL_CreateNode(3000);
    CLL_InsertNode(Current, NewNode);

    //Print List
    Count = CLL_GetNodeCount(List);
    for(i = 0; i < Count; i++){
        Current = CLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->data);
    }

    //Remove all Nodes from Memory
    printf("\nDestroying List...\n");

    Count = CLL_GetNodeCount(List);

    for(i = 0; i < Count; i++){
        Current = CLL_GetNodeAt(List, 0);

        if(Current != NULL){
            CLL_RemoveNode(&List, Current);
            CLL_DestroyNode(Current);
        }
    }

    return 0;
}