#include <stdio.h>
const int size = 5;

void push(int stack[], int *top);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[size];
    int top = -1;
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            push(stack, &top);
        } 
        else if (choice == 2) {
            pop(stack, &top);
        } 
        else if (choice == 3) {
            peek(stack, top);
        } 
        else if (choice == 4) {
            display(stack, top);
        } 
        else if (choice == 5) {
            printf("Program ended.\n");
            break;
        } 
        else {
            printf("Invalid option!\n");
        }
    }

    return 0;
}

void push(int stack[], int *top) {
    int num;
    if (*top == size - 1) {
        printf("Stack Overflow! Can't push more.\n");
    } else {
        printf("Enter number to push: ");
        scanf("%d", &num);
        *top = *top + 1;
        stack[*top] = num;
        printf("%d pushed into stack.\n", num);
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[*top]);
        *top = *top - 1;
    }
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}