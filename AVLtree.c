#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *left, *right;
    int height;
}Node;

int max(int a, int b){
    return (a> b)? a: b;
}

int height(Node *N){
    if(N == NULL) return 0;
    return N->height;
}

int getBalance(Node *N){
    if(N == NULL) return 0;
    return height(N->left) - height(N->right);
}

Node *createNode(int key){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> right = NULL;
    newNode -> left = NULL;
    newNode -> height = 1;
    newNode -> key =key;

    return newNode;
}

Node *rightRotate(struct Node* z){
    Node *y = z -> left;
    Node *T2 = y->right;

    y->right = z;
    z -> left = T2;

    y->height = 1 + max(height(y -> left), height(y -> right));
    z->height = 1 + max(height(z -> left), height(z -> right));

    return y;
}

Node *leftRotate(struct Node* z){
    Node *y = z -> right;
    Node *T2 = y->left;

    y->left = z;
    z -> right = T2;

    y->height = 1 + max(height(y -> left), height(y -> right));
    z->height = 1 + max(height(z -> left), height(z -> right));

    return y;
}

Node *insert(Node *node, int key){
    if(node == NULL){
        return createNode(key);
    }else if(key > node -> key){
        node -> right = insert(node->right, key);
    }else if(key < node -> key){
        node -> left = insert(node -> left, key);
    }else{
        return node;
    }

    // 높이 갱신
    node->height = 1 + max(height(node->left), height(node->right));

    // 균형 인수 확인
    int balance = getBalance(node);

    if(balance > 1 && key < node -> left -> key){
        return rightRotate(node);
    }
    
    if(balance < -1 && key > node -> right -> key){
        return leftRotate(node);
    }
    
    if(balance > 1 && key > node -> left -> key){
        node -> left = leftRotate(node -> left);
        return rightRotate(node);
    }

    if(balance < -1 && key < node -> right -> key){
        node -> right = rightRotate(node -> right);
        return leftRotate(node);
    }

    return node;


}

// 중위 순회 (확인용)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// 메인 함수 테스트
int main() {
    Node* root = NULL;

    // 삽입 테스트
    int values[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        root = insert(root, values[i]);
    }

    printf("중위 순회 결과 (정렬된 값): ");
    inorder(root);
    printf("\n");

    return 0;
}




















// #include <stdio.h>
// #include <stdlib.h>

// // 노드 정의
// typedef struct Node {
//     int key;
//     struct Node* left;
//     struct Node* right;
//     int height;
// } Node;

// // 최대값 함수
// int max(int a, int b) {
//     return (a > b) ? a : b;
// }

// // 노드 높이 반환
// int height(Node* N) {
//     if (N == NULL)
//         return 0;
//     return N->height;
// }

// // 새 노드 생성
// Node* createNode(int key) {
//     Node* node = (Node*)malloc(sizeof(Node));
//     node->key = key;
//     node->left = NULL;
//     node->right = NULL;
//     node->height = 1;  // 새 노드는 리프이므로 높이는 1
//     return node;
// }

// // 오른쪽 회전 (LL)
// Node* rightRotate(Node* y) {
//     Node* x = y->left;
//     Node* T2 = x->right;

//     // 회전 수행
//     x->right = y;
//     y->left = T2;

//     // 높이 갱신
//     y->height = max(height(y->left), height(y->right)) + 1;
//     x->height = max(height(x->left), height(x->right)) + 1;

//     return x;
// }

// // 왼쪽 회전 (RR)
// Node* leftRotate(Node* x) {
//     Node* y = x->right;
//     Node* T2 = y->left;

//     // 회전 수행
//     y->left = x;
//     x->right = T2;

//     // 높이 갱신
//     x->height = max(height(x->left), height(x->right)) + 1;
//     y->height = max(height(y->left), height(y->right)) + 1;

//     return y;
// }

// // 균형 인수 계산
// int getBalance(Node* N) {
//     if (N == NULL)
//         return 0;
//     return height(N->left) - height(N->right);
// }

// // 노드 삽입
// Node* insert(Node* node, int key) {
//     // 일반 이진 탐색 트리 삽입
//     if (node == NULL)
//         return createNode(key);

//     if (key < node->key)
//         node->left = insert(node->left, key);
//     else if (key > node->key)
//         node->right = insert(node->right, key);
//     else  // 중복 키는 허용하지 않음
//         return node;

//     // 높이 갱신
//     node->height = 1 + max(height(node->left), height(node->right));

//     // 균형 인수 확인
//     int balance = getBalance(node);

//     // 균형이 깨진 경우, 4가지 경우로 나눔

//     // LL 케이스
//     if (balance > 1 && key < node->left->key)
//         return rightRotate(node);

//     // RR 케이스
//     if (balance < -1 && key > node->right->key)
//         return leftRotate(node);

//     // LR 케이스
//     if (balance > 1 && key > node->left->key) {
//         node->left = leftRotate(node->left);
//         return rightRotate(node);
//     }

//     // RL 케이스
//     if (balance < -1 && key < node->right->key) {
//         node->right = rightRotate(node->right);
//         return leftRotate(node);
//     }

//     // 노드 반환
//     return node;
// }

// // 중위 순회 (확인용)
// void inorder(Node* root) {
//     if (root != NULL) {
//         inorder(root->left);
//         printf("%d ", root->key);
//         inorder(root->right);
//     }
// }

// // 메인 함수 테스트
// int main() {
//     Node* root = NULL;

//     // 삽입 테스트
//     int values[] = {10, 20, 30, 40, 50, 25};
//     for (int i = 0; i < 6; i++) {
//         root = insert(root, values[i]);
//     }

//     printf("중위 순회 결과 (정렬된 값): ");
//     inorder(root);
//     printf("\n");

//     return 0;
// }
