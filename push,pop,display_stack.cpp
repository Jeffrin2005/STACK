#include <stdio.h>
#define MAX 10  
int stack[MAX];
int top = -1;
void push(int value){
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int popped_value = stack[top];
        top--;
        printf("%d popped from stack\n", popped_value);
        return popped_value;
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;
    while (1) {  
        printf("Enter choice (1: push, 2: pop, 3: display, 0: exit): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        } else if (choice == 0) {
            printf("Exiting...\n");
            break; 
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
