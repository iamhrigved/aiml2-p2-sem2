#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    void* data;
    struct StackNode* prev;
} typedef node_t;

struct Stack {
    node_t* topmost_node;
    int length;
} typedef stack_t;

node_t create_new_node(void* data) {
    node_t node = {
        data,
        NULL
    };

    return node;
}

stack_t create_new_stack() {
    stack_t stack = {
        NULL,
        0
    };
    return stack;
}

void stack_push(stack_t* stack, node_t new_node_raw) {
    node_t* new_node = malloc(sizeof(new_node_raw));
    *new_node = new_node_raw;

    new_node->prev = stack->topmost_node;
    stack->topmost_node = new_node;

    stack->length++;
}

void* stack_pop(stack_t* stack) {
    if (stack->length == 0) return NULL;

    node_t* old_node = stack->topmost_node;
    void* data = old_node->data;

    stack->topmost_node = old_node->prev;
    free(old_node);
    stack->length--;

    return data;
}

void print_node(node_t* node) {
    // print every datatype as an int
    int* data_p = (int*)(node->data);
    printf("%d\n", *data_p);

    if (node->prev != NULL) print_node(node->prev);
}

void print_stack(stack_t* stack) {
    printf("CURRENT STACK:\n");
    print_node(stack->topmost_node);
    printf("---------------\n");
}

int main() {
    int* ele1 = malloc(4);
    *ele1 = 1;
    node_t node1 = create_new_node(ele1);

    int* ele2 = malloc(4);
    *ele2 = 2;
    node_t node2 = create_new_node(ele2);

    int* ele3 = malloc(4);
    *ele3 = 3;
    node_t node3 = create_new_node(ele3);

    int* ele4 = malloc(4);
    *ele4 = 4;
    node_t node4 = create_new_node(ele4);

    int* ele5 = malloc(4);
    *ele5 = 5;
    node_t node5 = create_new_node(ele5);

    stack_t stack = create_new_stack();
    stack_push(&stack, node1);
    stack_push(&stack, node2);
    stack_push(&stack, node3);
    stack_push(&stack, node4);
    stack_push(&stack, node5);

    print_stack(&stack);

    int* popped_element = stack_pop(&stack);
    printf("%d popped from the stack!\n", *popped_element);
    popped_element = stack_pop(&stack);
    printf("%d popped from the stack!\n\n", *popped_element);

    print_stack(&stack);
}