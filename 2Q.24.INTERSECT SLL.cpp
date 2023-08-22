#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int findLength(struct Node *head) {
    int length = 0;
    struct Node *current = head;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

struct Node *findIntersection(struct Node *head1, struct Node *head2) {
    int len1 = findLength(head1);
    int len2 = findLength(head2);

    int diff = abs(len1 - len2);

    struct Node *longerList = (len1 > len2) ? head1 : head2;
    struct Node *shorterList = (len1 > len2) ? head2 : head1;
    int i;
    for (i = 0; i < diff; i++) {
        longerList = longerList->next;
    }

    while (longerList != NULL && shorterList != NULL) {
        if (longerList == shorterList) {
            return longerList;
        }
        longerList = longerList->next;
        shorterList = shorterList->next;
    }

    return NULL; 
}

int main() {

    struct Node *common = (struct Node *)malloc(sizeof(struct Node));
    common->data = 5;
    common->next = NULL;

    struct Node *head1 = (struct Node *)malloc(sizeof(struct Node));
    head1->data = 1;
    head1->next = common;

    struct Node *head2 = (struct Node *)malloc(sizeof(struct Node));
    head2->data = 3;
    head2->next = common;

    struct Node *intersection = findIntersection(head1, head2);

    if (intersection != NULL) {
        printf("Intersection Point: %d\n", intersection->data);
    } else {
        printf("No Intersection Point\n");
    }
    free(common);
    free(head1);
    free(head2);

    return 0;
}
