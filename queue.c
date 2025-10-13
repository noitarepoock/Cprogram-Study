#include <stdio.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int rear = 0;
int front = 0;

int IsEpt(){
    if(rear == front) return true;
    else return false;
}

int IsFull(){
    if(front >= MAX_QUEUE_SIZE) return true;
    else return false;
}

void offer(int value){
    if(IsFull() == true){
        printf("queue full");
    }else{
        queue[front++] = value;
    }
}

int poll(){
    if(IsEpt() == true){
        printf("queue empty");
        return -1;
    }else{
        return queue[rear++];
    }
}


int main(void){
    offer(30);
    offer(20);
    offer(40);

    printf("%d\n", poll());
    printf("%d\n", poll());
    printf("%d\n", poll());
    printf("%d\n", poll());

    return 0;
}


//메모리 효율을 위해 구현한 원형 큐 나머지 연산을 통해 메모리를 아낌.
/*
#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = 0;
int rear = 0;

bool IsEmpty() {
    return front == rear;
}

bool IsFull() {
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

void offer(int value) {
    if (IsFull()) {
        printf("Queue full\n");
    } else {
        queue[rear] = value;
        rear = (rear + 1) % MAX_QUEUE_SIZE;
    }
}

int poll() {
    if (IsEmpty()) {
        printf("Queue empty\n");
        return -1;
    } else {
        int value = queue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
        return value;
    }
}

int main(void) {
    offer(30);
    offer(20);
    offer(40);

    printf("%d\n", poll());
    printf("%d\n", poll());
    printf("%d\n", poll());
    printf("%d\n", poll()); // 큐 비었을 때

    return 0;
}

*/
