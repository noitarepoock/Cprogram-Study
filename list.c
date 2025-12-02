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

//VITAMIN QUIZ
void SLL_InsertBefore(Node **Head, Node *Current, Node *NewNode){
    if((*Head) == NULL){
        (*Head) = NewNode;
    }
    if((*Head) == Current){
        NewNode->NextNode = (*Head);
        (*Head) = NewNode;
    }
    else{
        Node *Before = (*Head);
        while(Before->NextNode != Current){
            Before = Before->NextNode;
        }
        Before->NextNode = NewNode;
        NewNode->NextNode = Current;
    }
}

void SLL_DsetroyAllNodes(Node **List){
    Node *Current = *List;
    Node *Next = NULL;

    while(Current != NULL){
        Next = Current->NextNode;   // 다음 노드 저장
        free(Current);              // 현재 노드 삭제
        Current = Next;             // 다음 노드로 이동
    }

    *List = NULL;  // 리스트 완전 초기화
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

void SLL_InsertNewHead(Node **Head, Node *NewHead){
    if((*Head) == NULL){
        (*Head) = NewHead;
    }
    else{
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

int main(void){
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;

    //add 5nodes
    for(i = 0; i < 5; i++){
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    //print LIST
    Count = SLL_GetNodeCount(List);
    for(i = 0; i < Count; i++){
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nInserting 3000 After [2]...\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);

    SLL_InsertNode(Current, NewNode);

    //print LIST
    Count = SLL_GetNodeCount(List);
    for(i = 0; i < Count; i++){
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");

    // for(i = 0; i < Count; i++){
    //     Current = SLL_GetNodeAt(List, 0);

    //     if(Current != NULL){
    //         SLL_RemoveNode(&List, Current);
    //         SLL_DeleteNode(Current);
    //     }
    // }

    SLL_DsetroyAllNodes(&List);

    Count = SLL_GetNodeCount(List);
    for(i = 0; i < Count; i++){
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    if(Count == 0) printf("Emp");

    return 0;
}