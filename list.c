#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType Data;
    struct tagNode *NextNode;  //the address of nextNode
}Node;

// Node *SLL_CreateNode(ElementType NewData){
//     Node newNode;               //local variable
//     newNode.Data = NewData;
//     newNode.NextNode = NULL;
//     return &newNode;
// }                               //function end -> NewNode is removed in stack(자동 메모리)   


/***************************************************************************************************************************/
/*                                          create New Node need Heap(자유 저장소)                                          */
/***************************************************************************************************************************/




Node *SLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));         //memory allocated

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}                       //NewNode is not removed in Heap(자유 저장소)

void SLL_DeleteNode(Node *Node){
    free(Node);
}                       //Node is removed in Heap

void *SLL_AppendNode(Node **Head, Node *NewNode){
    if((*Head) == NULL){
        *Head = NewNode;
    }
    else{
        Node *Tail = (*Head);       //NextNode of Head
        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
    }
}

Node *SLL_GetNodeAt(Node *Head, int Location){
    Node *Current = Head;

    while(Current != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }

    return Current;
}

void SLL_RemoveNode(Node **Head, Node *Remove){
    if((*Head) == Remove){
        *Head = Remove -> NextNode;
    }
    else{
        Node *Curruent = *Head;
        while(*Head != NULL && Curruent->NextNode != Remove){
            Curruent = Curruent->NextNode;
        }
        if(Curruent != NULL){
            Curruent->NextNode = Remove->NextNode;
        }
    }
}

void SLL_InsertNode(Node *Current, Node *NewNode){      //changing only element of Current & Newnode
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

int SLL_GetNodeCount(Node *Head){
    int Count = 0;
    Node *Current = Head;

    while(Current != NULL){
        Current = Current->NextNode;
        Count++;
    }
    
    return Count;
}

int main(void){
    Node *List = NULL;
    Node *NewNode = NULL;
    Node *MyNode = NULL;
    NewNode = SLL_CreateNode(117);
    SLL_AppendNode(&List, NewNode);
    NewNode = SLL_CreateNode(119);
    SLL_AppendNode(&List, NewNode);
    SLL_AppendNode(&List, SLL_CreateNode(212));

    MyNode = SLL_GetNodeAt(List, 1);
    printf("%d\n", MyNode->Data);

    SLL_RemoveNode(&List, MyNode);
    SLL_DeleteNode(MyNode);


    return 0;
}