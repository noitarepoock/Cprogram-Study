/****************************************************************************************************************************************/
/*                                                             Calculator                                                               */
/****************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct tagNode{
    char *Data;
    struct tagNode *NextNode;
}Node;

typedef struct tagLinkedListStack{
    Node *List;
    Node *Top; //Tail
}LinkedListStack;

void LLS_CreateStack(LinkedListStack **Stack){
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

Node *LLS_CreateNode(char *NewData){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->Data = (char *)malloc(sizeof(char));

    strcpy(NewNode->Data, NewData);

    NewNode->NextNode = NULL;

    return NewNode;
}

void LLS_DestroyNode(Node *node){
    free(node->Data);
    free(node);
}

int LLS_IsEmpty(LinkedListStack *Stack){
    return Stack->List == NULL;
}

Node *LLS_Pop(LinkedListStack *Stack){
    Node *TopNode = Stack->Top;
    
    if(Stack->List == Stack->Top){
        Stack->List = NULL;
        Stack->Top = NULL;
    }else{
        Node *CurrentTop = Stack->List;
        while(CurrentTop != NULL && CurrentTop->NextNode != Stack->Top){
            CurrentTop = CurrentTop->NextNode;
        }

        Stack->Top = CurrentTop;
        Stack->Top->NextNode = NULL;
    }
    return TopNode;
}

void LLS_DestroyStack(LinkedListStack *Stack){
    while(!LLS_IsEmpty(Stack)){
        Node *Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }
    free(Stack);
}

void LLS_Push(LinkedListStack *Stack, Node *NewNode){
    if(Stack->List == NULL){
        Stack->List = NewNode;
    }else{
        Stack->Top->NextNode = NewNode;
    }

    Stack->Top = NewNode;
}

Node *LLS_Top(LinkedListStack *Stack){
    return Stack->Top;
}

int LLS_GetSize(LinkedListStack *Stack){
    int Count = 0;
    Node *Current = Stack->List;

    while(Current != NULL){
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

typedef enum{
    LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
    PLUS = '+', MINUS = '-',
    MULTIPLY = '*', DIVIDE = '/',
    SPACE = ' ', OPERAND
}SYMBOL;

int IsNumber(char Cipher);
unsigned int GetNextToken(char *Expression, char *Token, int *TYPE);
int IsPriror(char Operator1, char Operator2);
void GetPostfix(char *InfixExpression, char *PostfixExpression);
double Calculator(char *PostfixExpression);

char NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

int IsNumber(char Cipher){
    int i = 0;
    int ArrayLength = sizeof(NUMBER);

    for(i = 0; i < ArrayLength; i++){
        if(Cipher == NUMBER[i]) return 1;
    }

    return 0;
}

unsigned int GetNextToken(char *Expression, char *Token, int *TYPE){
    unsigned int i = 0;

    for(i = 0; 0 != Expression[i]; i++){
        Token[i] = Expression[i];

        if(IsNumber(Expression[i]) == 1){
            *TYPE = OPERAND;

            if(IsNumber(Expression[i+1]) != 1) break;
        }else{
            *TYPE = Expression[i];
            break;
        }
    }

    Token[++i] = '\0';
    return i;
}

int GetPriority(char Operator, int inStack){
    int Priority = -1;

    switch(Operator){
        case LEFT_PARENTHESIS:
            if(inStack)
                Priority = 3;
            else
                Priority = 0;
            break;
        
        case MULTIPLY:
        case DIVIDE:
            Priority = 1;
            break;
        
        case PLUS:
        case MINUS:
            Priority = 2;
            break;
    }

    return Priority;
}

int IsPrior(char OperatorInStack, char OperatorInToken){
    return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

void GetPostfix(char *InfixExpression, char *PostfixExpression){
    LinkedListStack *Stack;

    char Token[32];
    int Type = -1;
    unsigned int Position = 0;
    unsigned int Length = strlen(InfixExpression);

    LLS_CreateStack(&Stack);

    while(Position < Length){
        Position += GetNextToken(&InfixExpression[Position], Token, &Type); //POSITION OF NEXT TOKEN START

        if(Type == OPERAND){
            strcat(PostfixExpression, Token);
            strcat(PostfixExpression, " ");
        }
        else if(Type == RIGHT_PARENTHESIS){
            while(!LLS_IsEmpty(Stack)){
                Node *Popped = LLS_Pop(Stack);

                if(Popped->Data[0] == LEFT_PARENTHESIS){
                    LLS_DestroyNode(Popped);
                    break;
                }else{
                    strcat(PostfixExpression, Popped->Data);
                    LLS_DestroyNode(Popped);
                }
            }
        }else{
            while(!LLS_IsEmpty(Stack) && !IsPrior(LLS_Top(Stack)->Data[0], Token[0])){
                Node *Popped = LLS_Pop(Stack);

                if(Popped->Data[0] != LEFT_PARENTHESIS) strcat(PostfixExpression, Popped->Data);

                LLS_DestroyNode(Popped);
            }

            LLS_Push(Stack, LLS_CreateNode(Token));
        }
    }

    while(!LLS_IsEmpty(Stack)){
        Node *Popped = LLS_Pop(Stack);

        if(Popped->Data[0] != LEFT_PARENTHESIS) strcat(PostfixExpression, Popped->Data);

        LLS_DestroyNode(Popped);
    }

    LLS_DestroyStack(Stack);
}

double Calculate(char *PostfixExpression){
    LinkedListStack *Stack;
    Node *ResultNode;

    double Result;
    char Token[32];
    int Type = -1;
    unsigned int Read = 0;
    unsigned int Length = strlen(PostfixExpression);

    LLS_CreateStack(&Stack);

    while(Read < Length){
        Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

        if(Type == SPACE) continue;

        if(Type == OPERAND){
            Node *NewNode = LLS_CreateNode(Token);
            LLS_Push(Stack, NewNode);
        }
        else{
            char ResultString[32];
            double Operator1, Operator2, TempResult;
            Node *OperatorNode;

            OperatorNode = LLS_Pop(Stack);
            Operator2 = atof(OperatorNode->Data);
            LLS_DestroyNode(OperatorNode);

            OperatorNode = LLS_Pop(Stack);
            Operator1 = atof(OperatorNode->Data);
            LLS_DestroyNode(OperatorNode);

            switch(Type){
                case PLUS:      TempResult = Operator1 + Operator2; break;
                case MINUS:     TempResult = Operator1 - Operator2; break;
                case MULTIPLY:  TempResult = Operator1 * Operator2; break;
                case DIVIDE:    TempResult = Operator1 / Operator2; break;
            }

            gcvt(TempResult, 10, ResultString);
            LLS_Push(Stack, LLS_CreateNode(ResultString));
        }
    }

    ResultNode = LLS_Pop(Stack);
    Result = atof(ResultNode->Data);
    LLS_DestroyNode(ResultNode);
    LLS_DestroyStack(Stack);

    return Result;
}

int main(void){
    char InfixExpression[100];
    char PostfixExpression[100];

    double Result = 0.0;

    memset(InfixExpression, 0, sizeof(InfixExpression));
    memset(PostfixExpression, 0, sizeof(PostfixExpression));

    printf("Enter Infix Expression : ");
    scanf("%s", InfixExpression);

    GetPostfix(InfixExpression, PostfixExpression);

    printf("Infix : %s\nPostfix : %s\n", InfixExpression,PostfixExpression);

    Result = Calculate(PostfixExpression);
    printf("Calculation Result : %f\n", Result);

    return 0;
}