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

void DLL_InsertNode(Node *Current, Node *NewNode){
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if(Current->NextNode != NULL){
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

void DLL_RemoveNode(Node **Head, Node *Remove){
    if((*Head) == Remove){
        *Head = Remove->NextNode;
        if((*Head) != NULL){
            (*Head)->PrevNode = NULL;
        }
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }else{
        Node *Temp = Remove;
        if(Remove->NextNode != NULL){
            Remove->NextNode->PrevNode = Temp->PrevNode;
        }
        if(Remove->PrevNode != NULL){
            Remove->PrevNode->NextNode = Temp->NextNode;
        }
        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }
}

Node *DLL_GetNodeAt(Node *Head, int Location){
    Node *Current = Head;

    while(Head != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }
    return Current;
}

int DLL_GetNodeCount(Node *Head){
    unsigned int Count = 0;
    Node *Current = Head;

    while(Current != NULL){
        Current = Current->NextNode;
        Count++;
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

int main(void){
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *NewNode = NULL;
    Node *Current = NULL;

    //Add 5Nodes
    for(i = 0; i < 5; i++){
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    //Print List
    Count = DLL_GetNodeCount(List);
    for(i = 0; i < Count; i++){
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->data);
    }

    //Add Node After 3rd Node
    printf("\nInserting 3000 After [2]...\n");

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertNode(Current, NewNode);

    //Print List
    Count = DLL_GetNodeCount(List);
    for(i = 0; i < Count; i++){
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->data);
    }

    //Remove all Nodes from Memory
    printf("\nDestroying List...\n");

    Count = DLL_GetNodeCount(List);

    for(i = 0; i < Count; i++){
        Current = DLL_GetNodeAt(List, 0);

        if(Current != NULL){
            DLL_RemoveNode(&List, Current);
            DLL_DestroyNode(Current);
        }
    }

    return 0;
}