#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_HEAP_SIZE 100


typedef struct{
    int heap[MAX_HEAP_SIZE];
    int size;
}PriorityQueue;

void init(PriorityQueue *pq){       //setting PriorityQueue's SIZE == 0
    pq->size = 0;
}

void push(PriorityQueue *pq, int value){
    if(pq->size > MAX_HEAP_SIZE - 1){
        printf("HEAP OVERFLOW");
        return;
    }

    int i = (pq->size)++;
    pq->heap[i] = value;

    while(i > 0){
        int parent = (i - 1) / 2;

        if(pq->heap[parent] >= pq->heap[i]) break;

        if(pq->heap[parent] < pq->heap[i]){
            int tmp = pq->heap[parent];
            pq->heap[parent] = pq->heap[i];
            pq->heap[i] = tmp;

            i = parent;
        }
    }
}

int pop(PriorityQueue *pq){
    if(pq->size == 0){
        printf("HEAP EPT");
        return -1;
    }

    int root = pq->heap[0];
    int last = pq->heap[--pq->size];

    int parent = 0;
    int child = 1;

    while(child < pq->size){
        if(child + 1 < pq->size && pq->heap[child] < pq->heap[child+1]) child++;

        if(last >= pq->heap[child]) break;

        pq->heap[parent] = pq->heap[child];
        parent = child;
        child = parent * 2 + 1;
    }
    pq->heap[parent] = last;

    return root;
}

void printHeap(PriorityQueue *pq) {
    printf("Heap: ");
    for (int i = 0; i < pq->size; i++)
        printf("%d ", pq->heap[i]);
    printf("\n");
}

int main(void){
    PriorityQueue pq;
    init(&pq);

    push(&pq, 45);
    push(&pq, 20);
    push(&pq, 14);
    push(&pq, 30);
    push(&pq, 10);
    push(&pq, 50);

    printHeap(&pq);

    printf("pop: %d\n", pop(&pq));
    printHeap(&pq);

    printf("pop: %d\n", pop(&pq));
    printHeap(&pq);

    return 0;
}