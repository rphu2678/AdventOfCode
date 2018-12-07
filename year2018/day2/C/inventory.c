#include <stdio.h>
#include <stdlib.h>

int find_n_occurrences(char* string, int occurrences){
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++){
        for(int j = 0; string[j] != '\0'; j++){
            count += string[j] == string[i];
        }
        if (count == occurrences){
            return 1;
        }
        count = 0;
    }
    return 0;
}

int main(){
    char input[30];
    int two_count = 0, three_count = 0;
    FILE* fp = fopen("input.txt", "r");
    if(fp == NULL){
        printf("Error. Could not open file!");
        exit(-1);
    }
    while(fscanf(fp, "%s", &input) != EOF){
        two_count += find_n_occurrences(input, 2);
        three_count += find_n_occurrences(input, 3);
    }
    printf("Checksum: %d", two_count * three_count);
    return 0;
}

