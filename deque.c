#include <stdio.h>
#include <stdbool.h>
#define MAX_DEQUE_SIZE 100

int deque[MAX_DEQUE_SIZE];
int front = 0;
int rear = 0;

bool IsEpt(){
    return front == rear;
}

bool IsFull(){
    return (rear+1) % MAX_DEQUE_SIZE == front;
}

int dequeue(){
    if(IsEpt() == true){
        printf("deque empty");
        return -1;
    }else{
        int value = deque[front];
        front = (front + 1) % MAX_DEQUE_SIZE;            //front -> front + 1
        return value;
    }
}

int get_front(){
    if(IsEpt() == true){
        printf("deque empty");
        return -1;
    }else{
        return deque[front];
    }
}

void add_front(int value){
    if(IsFull() == true){
        printf("deque Full");
    }else{
        front = (front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
        deque[front] = value;
    }
}

void enqueue(int value){
    if(IsFull() == true){
        printf("deque Full");
    }else{
        deque[rear] = value;
        rear = (rear + 1) % MAX_DEQUE_SIZE;
    }
}

int delete_rear(){
    if(IsEpt() == true){
        printf("deque empty");
        return -1;
    }else{
        int value = deque[rear];
        rear = (rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
        return value;
    } 
}

int get_rear(){
    if(IsEpt() == true){
        printf("deque empty");
        return -1;
    }else{
        return deque[rear];
    }
}

int main(void){
    add_front(30);
    add_front(20);
    add_front(10);
    add_front(30);
    add_front(20);
    add_front(10);
    add_front(30);
    add_front(20);
    add_front(10);
    add_front(30);
    add_front(20);
    add_front(10);

    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", get_front());
    printf("%d\n", dequeue());

    enqueue(50);
    enqueue(60);
    printf("%d\n",delete_rear());
    printf("%d\n", get_rear());
    printf("%d\n", delete_rear());

    return 0;
}

/*
#include <stdio.h>
#include <stdbool.h>

#define MAX_DEQUE_SIZE 100

typedef struct {
    int data[MAX_DEQUE_SIZE];
    int front;
    int rear;
} Deque;

// ---------- 기본 유틸 ----------
void initDeque(Deque* dq) {
    dq->front = 0;
    dq->rear = 0;
}

bool isEmpty(Deque* dq) {
    return dq->front == dq->rear;
}

bool isFull(Deque* dq) {
    return (dq->rear + 1) % MAX_DEQUE_SIZE == dq->front;
}

// ---------- 연산 ----------
void addFront(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque Full\n");
        return;
    }
    dq->front = (dq->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    dq->data[dq->front] = value;
}

void addRear(Deque* dq, int value) {  // enqueue() 와 동일
    if (isFull(dq)) {
        printf("Deque Full\n");
        return;
    }
    dq->data[dq->rear] = value;
    dq->rear = (dq->rear + 1) % MAX_DEQUE_SIZE;
}

int deleteFront(Deque* dq) {  // dequeue() 와 동일
    if (isEmpty(dq)) {
        printf("Deque Empty\n");
        return -1;
    }
    int value = dq->data[dq->front];
    dq->front = (dq->front + 1) % MAX_DEQUE_SIZE;
    return value;
}

int deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Empty\n");
        return -1;
    }
    dq->rear = (dq->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return dq->data[dq->rear];
}

int getFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Empty\n");
        return -1;
    }
    return dq->data[dq->front];
}

int getRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Empty\n");
        return -1;
    }
    int idx = (dq->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return dq->data[idx];
}

// ---------- 디버깅용 ----------
void printDeque(Deque* dq) {
    if (isEmpty(dq)) {
        printf("[empty]\n");
        return;
    }

    printf("Deque: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->data[i]);
        i = (i + 1) % MAX_DEQUE_SIZE;
    }
    printf("\n");
}

// ---------- 테스트 ----------
int main(void) {
    Deque dq;
    initDeque(&dq);

    addFront(&dq, 10);
    addFront(&dq, 20);
    addFront(&dq, 30);
    addRear(&dq, 40);
    addRear(&dq, 50);

    printDeque(&dq);

    printf("deleteFront: %d\n", deleteFront(&dq));
    printf("deleteRear: %d\n", deleteRear(&dq));

    printDeque(&dq);

    printf("Front: %d\n", getFront(&dq));
    printf("Rear: %d\n", getRear(&dq));

    return 0;
}

*/