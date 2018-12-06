#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chronical_calibration.h"
#include "linked_list.h"

int main(){
    char input[12];
    Node* head, *tail;
    init_list(&head, &tail);

    FILE* f = fopen("../input.txt", "r");
    if (f == NULL){
        printf("Error! Could not open file!\n");
        exit(-1);
    }
    printf("Checksum = %d\n", get_checksum(f));
    clock_t t = clock();
    printf("First repeat frequency: %d\n", find_first_repeat(head, tail, f));
    printf("Time: %f", (double)(clock() - t) / CLOCKS_PER_SEC);

    return 0;
}

int get_checksum(FILE* file){
    char input[12] = "";
    int sum = 0;
    while(fscanf(file, "%s", &input) != EOF){
        sum += atoi(input);
    }
    return sum;
}

int find_first_repeat(Node* head, Node* tail, FILE* f){
    char input[12] = "";
    int sum = 0;
    int exists = 0;
    Node* node;
    while(1){
        fseek(f, 0, SEEK_SET);
        while(fscanf(f, "%s", &input) != EOF){
            sum += atoi(input);
            exists = search_num(head, sum);
            if(exists){
                break;
            }
            node = malloc(sizeof(Node));
            node->val = sum;
            node->next = NULL;
            add_item(&tail, node);
            //printf("%d\n", sum);
        }
        if(exists){
            break;
        }
    }

    return sum;
}