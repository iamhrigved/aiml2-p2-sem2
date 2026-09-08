#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int value;
    struct Element* next;
} element_t;

element_t *queue_head = NULL;
element_t *queue_tail = NULL;

int insert_queue(int value) {
    element_t *new_element = malloc(sizeof(element_t));
    new_element->value = value;
    new_element->next = NULL;

    printf("--- Inserting item: %d ---\n", value);

    if (!queue_head) {
        queue_head = new_element;
        queue_tail = new_element;
        return 1;
    }

    queue_tail->next = new_element;
    queue_tail = new_element;
    return 1;
}

int delete_queue() {
    if (!queue_head && !queue_tail) return -1;

    element_t *temp = queue_head;

    if (queue_head == queue_tail) queue_head = queue_tail = NULL;
    else queue_head = queue_head->next;

    printf("--- Deleting item: %d ---\n", temp->value);
    free(temp);

    return 1;
}

void display_queue() {
    element_t *temp = queue_head;

    printf("--------- CURRENT QUEUE ---------\n");
    for (; temp != NULL; temp = temp->next) {
        printf("In queue: %d\n", temp->value);
    }
    printf("---------------------------------\n");
}

int main() {
    insert_queue(10);
    insert_queue(20);
    insert_queue(30);
    insert_queue(40);
    insert_queue(50);

    display_queue();

    delete_queue();
    delete_queue();

    display_queue();

    insert_queue(60);
    insert_queue(70);

    display_queue();
}