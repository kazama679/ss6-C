#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 

typedef struct {
    char array[MAX]; 
    int top;
} Stack;

void inital(Stack* stack) {
    stack->top = -1; 
}

int isEmpty(Stack* stack) {
    return stack->top == -1; 
}

int isFull(Stack* stack) {
    return stack->top >= MAX - 1; 
}

void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Ngan xep da day, khong the them!\n");
        return;
    }
    stack->array[++stack->top] = value;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong, khong the lay phan tu!\n");
        return '\0'; 
    }
    return stack->array[stack->top--];
}

int checkXemDauGi(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

void checkHopLe(char* str) {
    Stack stack;
    inital(&stack);
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char current = str[i];
        if (current == '(' || current == '{' || current == '[') {
            push(&stack, current);
        }
        else if (current == ')' || current == '}' || current == ']') {
            if (isEmpty(&stack)) {
                printf("Bieu thuc khong hop le!\n");
                return;
            }
            char top = pop(&stack);
            if (!checkXemDauGi(top, current)) {
                printf("Bieu thuc khong hop le!\n");
                return;
            }
        }
    }
    if (isEmpty(&stack)) {
        printf("Bieu thuc hop le!");
    } else {
        printf("Bieu thuc khong hop le!");
    }
}

int main() {
    char input[MAX];
    printf("Nhap mot chuoi (toi da 100 ky tu): ");
    fgets(input, MAX, stdin); 
    input[strcspn(input, "\n")] = '\0';
    checkHopLe(input);
    return 0;
}

