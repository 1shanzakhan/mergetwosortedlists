#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);

int main() {
    printf("Enter the number of elements for the first linked list: ");
    int n1;
    scanf("%d", &n1);
    struct ListNode* l1 = NULL;
    struct ListNode* tail1 = NULL;
    printf("Enter the elements of the first linked list: ");
    for (int i = 0; i < n1; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = val;
        node->next = NULL;
        if (l1 == NULL) {
            l1 = node;
            tail1 = node;
        } else {
            tail1->next = node;
            tail1 = node;
        }
    }

    printf("Enter the number of elements for the second linked list: ");
    int n2;
    scanf("%d", &n2);
    struct ListNode* l2 = NULL;
    struct ListNode* tail2 = NULL;
    printf("Enter the elements of the second linked list: ");
    for (int i = 0; i < n2; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = val;
        node->next = NULL;
        if (l2 == NULL) {
            l2 = node;
            tail2 = node;
        } else {
            tail2->next = node;
            tail2 = node;
        }
    }

    struct ListNode* result = mergeTwoLists(l1, l2);

    printf("Merged linked list: ");
    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");

    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    struct ListNode *result = NULL;
    
    if (list1->val < list2->val) {
        result = list1;
        list1 = list1->next;
    }
    else {
        result = list2;
        list2 = list2->next;
    }

    struct ListNode *current = result;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != NULL) {
        current->next = list1;
    }
    else {
        current->next = list2;
    }

    return result;

}
