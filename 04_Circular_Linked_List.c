
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void insertBeginning(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertEnd(int data) {
    insertBeginning(data);
    last = last->next;
}

void deleteBeginning() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *head = last->next;

    if (head == last) {
        last = NULL;
    } else {
        last->next = head->next;
    }

    free(head);
}

void deleteEnd() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *head = last->next;

    if (head == last) {
        free(last);
        last = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next != last) {
        temp = temp->next;
    }

    temp->next = last->next;
    free(last);
    last = temp;
}

void display() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = last->next;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to head)\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}