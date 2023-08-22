#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return 1; 
    }

    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev_slow = head;
    struct Node* second_half;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    if (fast != NULL) {
        slow = slow->next; 
    }

    second_half = reverseList(slow);
    prev_slow->next = NULL; 
    struct Node* temp1 = head;
    struct Node* temp2 = second_half;

    int palindrome = 1;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            palindrome = 0;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    
    second_half = reverseList(second_half);
    prev_slow->next = second_half;

    return palindrome;
}

int main() {

    struct Node* head = NULL;

    appendNode(&head, 'r');
    appendNode(&head, 'a');
    appendNode(&head, 'd');
    appendNode(&head, 'a');
    appendNode(&head, 'r');

    if (isPalindrome(head)) {
        printf("\nThe linked list is a palindrome.\n");
    } else {
        printf("\nThe linked list is not a palindrome.\n");
    }

    
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
