#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void init_list(Node** head, Node** tail){
    *head = malloc(sizeof(Node));
    (*head)->val = 0;
    (*head)->next = NULL;
     *tail = *head;
}

void add_item(Node** tail, Node* item){
    (*tail)->next = item;
    *tail = (*tail)->next;
}

int search_num(Node* head, int val){
    int found = head->val == val;
    Node* temp = head;
    if (!found){
        while(temp->next != NULL){
            temp = temp->next;
            found = temp->val == val;
            if(found){
                break;
            }
        }
    }
    return found;
}