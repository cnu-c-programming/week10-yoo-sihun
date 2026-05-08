#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[20];
    int score;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    char cmd[10];

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "add") == 0) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            scanf("%s %d", newNode->name, &newNode->score);
            newNode->next = NULL;
            if (head == NULL) {
                head = newNode;
            } else {
                struct Node* temp = head;
                while (temp->next != NULL) temp = temp->next;
                temp->next = newNode;
            }
        } else if (strcmp(cmd, "delete") == 0) {
            char name[20];
            scanf("%s", name);
            struct Node *curr = head, *prev = NULL;
            while (curr != NULL && strcmp(curr->name, name) != 0) {
                prev = curr;
                curr = curr->next;
            }
            if (curr != NULL) {
                if (prev == NULL) head = curr->next;
                else prev->next = curr->next;
                free(curr);
            }
        } else if (strcmp(cmd, "print") == 0) {
            struct Node* temp = head;
            while (temp != NULL) {
                printf("%s %d\n", temp->name, temp->score);
                temp = temp->next;
            }
        } else if (strcmp(cmd, "quit") == 0) {
            struct Node* curr = head;
            while (curr != NULL) {
                struct Node* next = curr->next;
                free(curr);
                curr = next;
            }
            break;
        }
    }
    return 0;
}
