#include<stdio.h>
#include<stdlib.h>
#define MAX 5  

// C?u tr�c ng�n x?p
typedef struct {
    int array[MAX];  
    int top; 
} Stack; 

// Khoi tao cac phep toan
void inital(Stack* stack) {
    stack->top = -1; 
}

// Kiem tra ngan xep c� rong hay khong
int isEmpty(Stack* stack) {
    if (stack->top == -1) {
        return 1;  // true 
    }
    return 0;  // false 
} 

// Kiem tra ngan xep day hay khong
int isFull(Stack* stack) {
    if (stack->top >= MAX - 1) {
        return 1; 
    }
    return 0; 
} 

// Them 
void push(Stack* stack, int value) {
    if (isFull(stack) == 1) {
        printf("Ngan xep da day, khong them dc!\n"); 
        return; 
    }
    stack->array[++(stack->top)] = value; 
} 

void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return;
    }
    printf("Ngan xep k rong");
}

int main() {
    int n;
    printf("Nhap n: ");
	scanf("%d", &n); 
    if(n<0 || n>100){
    	printf("Vui long nhap trong khoang 0 - 100");
		return 0; 
	} 
    int value[n];
    Stack stack;
    inital(&stack);
    
	for(int i=0; i<n; i++){
		printf("Nhap gia tri %d: ", i+1);
		scanf("%d", &value[i]); 
	    push(&stack, value[i]);
	} 
    // in ra
	printStack(&stack);

    return 0;
}
