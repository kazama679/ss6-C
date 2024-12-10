#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 
#include <ctype.h>

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
        return 0; 
    }
    return stack->array[stack->top--];
}

void chuoiDaoNguoc(char* str) {
    Stack stack;
    inital(&stack);
    char filtered[MAX];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) { 
            filtered[j++] = tolower(str[i]);
        }
    }
    filtered[j] = '\0'; 
    int length = strlen(filtered);
    for (int i = 0; i < length / 2; i++) {
        if (filtered[i] != filtered[length - i - 1]) {
            printf("Ko p doi xung!\n");
            return;
        }
    }
    printf("Doi xung\n");
}

int main() {
    char input[MAX];

    printf("Nhap mot chuoi (toi da 100 ky tu): "); 
    fgets(input, MAX, stdin); 
    input[strcspn(input, "\n")] = '\0'; 

    chuoiDaoNguoc(input);

    return 0;
}
