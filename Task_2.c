#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *new, *head = NULL, *current;

// Function to create a singly linked list
void create() {
    int n;
    printf("Enter the number of nodes in the singly linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &new->data);
        new->next = NULL;
        if (head == NULL) {
            head = new;
            current = new;
        } else {
            current->next = new;
            current = new;
        }
    }
}

// Function to display all nodes in the singly linked list
void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert at the beginning
void insert_at_begin() {
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert at the beginning: ");
    scanf("%d", &new->data);
    new->next = head;
    head = new;
}

// Function to insert at the end
void insert_at_end() {
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert at the end: ");
    scanf("%d", &new->data);
    new->next = NULL;
    current = head;
    if (current == NULL) {
        head = new;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
}

// Function to insert at a specific location
void insert_at_loc() {
    int ele;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert at a specific location: ");
    scanf("%d", &new->data);
    printf("Enter the element after which the new node has to be inserted: ");
    scanf("%d", &ele);
    current = head;
    while (current != NULL && current->data != ele) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found.\n");
        free(new);
        return;
    }
    new->next = current->next;
    current->next = new;
}

// Function to delete a node at the beginning
void delete_at_begin() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *ptr = head;
    head = ptr->next;
    free(ptr);
}

// Function to delete a node at the end
void delete_at_end() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *ptr = head, *tptr = NULL;
    while (ptr->next != NULL) {
        tptr = ptr;
        ptr = ptr->next;
    }
    if (tptr != NULL) {
        tptr->next = NULL;
    } else {
        head = NULL;
    }
    free(ptr);
}

// Function to delete a node at a specific location
void delete_at_middle() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    int ele;
    struct node *ptr = head, *tptr = NULL;
    printf("Enter the element to be deleted: ");
    scanf("%d", &ele);
    while (ptr != NULL && ptr->data != ele) {
        tptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Element not found.\n");
        return;
    }
    if (tptr == NULL) {
        head = ptr->next;
    } else {
        tptr->next = ptr->next;
    }
    free(ptr);
}

// Main Function
int main() {
    int choice;
    while (1) {
        printf("\n1. Create\t2. Insert at Beginning\t3. Insert at Location\t4. Insert at End\n");
        printf("5. Delete at Beginning\t6. Delete at Middle\t7. Delete at End\t8. Display\t9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert_at_begin();
                break;
            case 3:
                insert_at_loc();
                break;
            case 4:
                insert_at_end();
                break;
            case 5:
                delete_at_begin();
                break;
            case 6:
                delete_at_middle();
                break;
            case 7:
                delete_at_end();
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}
