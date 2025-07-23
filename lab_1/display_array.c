#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <time.h>

typedef struct {
    int occurance; 
    int value; 
}value_occ_pair;

int compare_fun(const void *a, const void *b){
    int val1 = *(const int *)a;
    int val2 = *(const int *)b;
    return val1-val2; 
}

void print_arr(int *arr, size_t len){
    printf("{");
    for(size_t i=0; i<len; i++){
        printf("%d, ", arr[i]);
    }
    printf("\b\b}\n");

    return;
}

int count_element(int *arr, size_t len, int int_num){
    int count = 0; 
    for(size_t i=0; i<len; i++){ 
        if(arr[i] == int_num){
            count++;
        }
    }

    return count;
}

value_occ_pair* assing_value_occ_pair(int *arr, size_t len){
    size_t i = 0;

    value_occ_pair *return_arr = (value_occ_pair*)calloc(sizeof(value_occ_pair) ,len);

    int arr_pos = 0;
    while (i < len){
        size_t count = 1;
        while (i+1< len && arr[i] == arr[i+1]){
            count++;
            i++;
        }
        return_arr[arr_pos].occurance = count;
        return_arr[arr_pos].value = arr[i];
        i++;
        arr_pos++;
    }
    
    return return_arr;
}

void bubble_sort(value_occ_pair* arr, size_t len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-1; j++){
            if(arr[j].occurance >= arr[j+1].occurance){
                value_occ_pair temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    printf("enter the number of elements: ");
    size_t len; 
    scanf("%zu", &len);

    srand(time(NULL));

    int arr[len];

    for(size_t i=0; i<len; i++){
        arr[i] = rand()%2;
    }

    //qsort(arr, len, sizeof(int), compare_fun);
    print_arr(arr, len);
    int zero_count = count_element(arr, len, 0);
    int one_count = count_element(arr, len, 1);
    //printf("number of zeroes: %d\nnumber of ones: %d\n", zero_count, one_count);

    value_occ_pair *data_pair = assing_value_occ_pair(arr, len);
    size_t data_pair_len = len;

    bubble_sort(data_pair, len);
    
    // for(int j=0; j<len; j++){
    //     printf("%d-%d\n", data_pair[j].occurance, data_pair[j].value);
    // }

    int sorted_array_by_occurance[len];
    int sorted_arr_postion = 0;
    for(int i=0; i<len; i++){
        for(int j=0; j<data_pair[i].occurance; j++){
            sorted_array_by_occurance[sorted_arr_postion++] = data_pair[i].value;
        }
    }

    print_arr(sorted_array_by_occurance, len);

    printf("\n");
    return 0;
}