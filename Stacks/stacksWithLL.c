#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

void push(struct Node**);
void showStack(struct Node*);
int pop(struct Node**);
int topElement(struct Node*);
void deleteStack(struct Node**);

int main() {

    int userChoice = 0;     // takes user choice for what action to perform.
    struct Node *top = NULL;
    printf("Hello, this is a simple stak implementation using Linked Lists");
    do {
        printf("Please enter the following choices : \n 1. To view the contents of the stack \n 2. To add an element to the stack \n 3. Remove the top most element \n 4. View the top most element. \n 5. Delete the stack.\n");
        scanf(" %d", &userChoice);
        switch(userChoice) {
            case 0:
                printf("Thank you for using stacks\n");
                break;
            case 1:
                showStack(top);
                break;
            case 2:
                push(&top);
                break;
            case 3:
                pop(&top);
                break;
            case 4:
                topElement(top);
                break;
            case 5:
                deleteStack(&top);
            default:
                printf("This is an invalid choice, please try again!\n");
        }
    }
    while(userChoice);
}

void push(struct Node **top) {
    printf("\n============================================\n");
    int newData;
    printf("Please enter the value you want to add\n");
    scanf(" %d", &newData);
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = newData;
    temp->next = *top;
    *top = temp;
    printf("\n============================================\n");
}

void showStack(struct Node *top) {
    printf("\n============================================\n");
    printf("Below are the contents of the existing stack\n");
    while (top) {
        printf("%d\n", top->data);
        top = top->next;
    }
    printf("\n============================================\n");
}

int pop(struct Node **top) {
    printf("\n============================================\n");
    if (*top) {
        struct Node *temp = *top;
        int returnData = temp->data;
        *top = temp->next;
        free(temp);
        printf("the popped element is: %d \n", returnData);
        printf("\n============================================\n");
        return returnData;
    }
    printf("Stack is empty.\n");
    printf("\n============================================\n");
    return -1;
}

int topElement(struct Node *top) {
    printf("\n============================================\n");
    if (top) {
        printf("The element at the top is: %d\n", top->data);
        printf("\n============================================\n");
        return top->data;
    }
    printf("The stack is empty");
    printf("\n============================================\n");
    return -1;
}

void deleteStack(struct Node **top) {
    printf("\n============================================\n");
    // struct Node *temp = *top;
    // struct Node *nextNode;
    // while(temp) {
    //     nextNode = temp->next;
    //     free(temp);
    //     temp = nextNode;
    // }
    // // free(*top);

    struct Node *temp, *p;
    p = *top;
    while(p->next) {
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
    free(p);
    printf("Stack deleted successfully");
    printf("\n============================================\n");
}