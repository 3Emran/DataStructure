C program implement queue using two stacks using  enqueue costly


#include <stdio.h>


// Stack structure
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
bool isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

// Function to peek the top item of stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top];
}

// Queue structure using two stacks
struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

// Function to create a queue using two stacks
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

// Function to add an item to the queue
void enQueue(struct Queue* queue, int item) {
    // Move all elements from stack1 to stack2
    while (!isEmpty(queue->stack1)) {
        push(queue->stack2, pop(queue->stack1));
    }

    // Push the new item onto stack1
    push(queue->stack1, item);

    // Move all elements back to stack1
    while (!isEmpty(queue->stack2)) {
        push(queue->stack1, pop(queue->stack2));
    }
}

// Function to remove an item from the queue
int deQueue(struct Queue* queue) {
    if (isEmpty(queue->stack1)) {
        printf("Queue is empty!\n");
        return -1; // Indicate that the queue is empty
    }
    return pop(queue->stack1);
}

// Function to get the front item of the queue
int front(struct Queue* queue) {
    if (isEmpty(queue->stack1)) {
        printf("Queue is empty!\n");
        return -1; // Indicate that the queue is empty
    }
    return peek(queue->stack1);
}

// Function to check if the queue is empty
bool isQueueEmpty(struct Queue* queue) {
    return isEmpty(queue->stack1);
}

// Main function to demonstrate the queue operations
int main() {
    struct Queue* queue = createQueue(100);

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);

    printf("Front element is: %d\n", front(queue)); // Should print 1

    printf("Dequeued: %d\n", deQueue(queue)); // Should print 1
    printf("Dequeued: %d\n", deQueue(queue)); // Should print 2

    enQueue(queue, 4);
    printf("Front element is: %d\n", front(queue)); // Should print 3


}
