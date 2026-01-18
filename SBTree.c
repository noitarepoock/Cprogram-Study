/****************************************************************************************************************************************/
/*                                                         SIMPLE BINARY TREE                                                           */
/****************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char ElementType;

typedef struct tagSBTNode{
    struct tagSBTNode *Left;
    struct tagSBTNode *Right;

    ElementType Data;
}SBTNode;

SBTNode *SBT_CreateNode(ElementType NewData){
    SBTNode *NewNode = (SBTNode*)malloc(sizeof(SBTNode));       //memoryAllocate
    NewNode->Left = NULL;
    NewNode->Right = NULL;

    NewNode->Data = NewData;

    return NewData;
}

void SBT_DestroyNode(SBTNode *Node){
    free(Node);                                                 //MemoryFree
}


void SBT_DestroyTree(SBTNode *Root){
    if(Root == NULL) return;
    
    SBT_DestroyTree(Root->Left);
    SBT_DestroyTree(Root->Right);
    SBT_DestroyNode(Root);
}


void SBT_PreorderPrintTree(SBTNode *Node){
    if(Node == NULL) return;

    printf(" %c",Node->Data);

    SBT_PreorderPrintTree(Node->Left);
    SBT_PreorderPrintTree(Node->Right);
}

void SBT_InorderPrintTree(SBTNode *Node){
    if(Node == NULL) return;

    SBT_InorderPrintTree(Node->Left);
    printf(" %c", Node->Data);
    SBT_InorderPrintTree(Node->Right);
}

void SBT_PostorderPrintTree(SBTNode *Node){
    if(Node == NULL) return;

    SBT_PostorderPrintTree(Node->Left);
    SBT_PostorderPrintTree(Node->Right);
    printf(" %c", Node->Data);
}


int main(void){
    
}