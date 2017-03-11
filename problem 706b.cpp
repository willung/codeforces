#include <iostream>
#include <time.h>

#define MAX_PRICE  100000000    //maximum value price can take (x_i)
#define MAX_DAYS   100000       //maximum days of buying (q)
#define MAX_SHOPS  100000       //maximum number of shops n

/*
#define MAX_MONEY  1000000000
*/

using namespace std;

void merge_sort(int* unsorted_array, int* sorted_array, int start, int end);

void merge_arrays(int* unsorted_array, int* sorted_array, int start, int end); 

int binary_search(int* search_array, int item, int start, int end); 

int main(void) {
    int i, j, prices[MAX_SHOPS], sorted_prices[MAX_SHOPS], n_shops, n_days, sum_shops=0, index=0;
    long long coins[MAX_DAYS];
   
    cin >> n_shops;
    for (i=0; i<n_shops; i++) {
        cin >> prices[i];
        sorted_prices[i] = prices[i];
    }

    merge_sort(prices,sorted_prices,0,n_shops-1);

    cin >> n_days;
    for (i=0; i<n_days; i++) {
        cin >> coins[i];
        cout << binary_search(sorted_prices,coins[i],0,n_shops)+1 << endl;
    }
    
    return 0;
}

void merge_sort(int* unsorted_array, int* sorted_array, int start, int end) {
    int middle = (start+end)/2;  //middle is integer, so floor
    //do nothing if array of length 1 or 2
    if (end-start == 0) {
        return; 
    }
    
    merge_sort(sorted_array, unsorted_array, start, middle);
    merge_sort(sorted_array, unsorted_array, middle+1, end);
    
    merge_arrays(unsorted_array, sorted_array, start, end);
}

void merge_arrays(int* unsorted_array, int* sorted_array, int start, int end) {
    int i, middle = (start+end)/2, left_value, right_value;
    int left_run=start, right_run=middle+1;

    for (i=start; i<=end; i++) {
        left_value = unsorted_array[left_run];
        right_value = unsorted_array[right_run];
        if (left_run <= middle && (right_run > end || left_value < right_value)) {
            sorted_array[i] = left_value;
            left_run++;
        } else {
            sorted_array[i] = right_value;
            right_run++;
        }
    }

}

int binary_search(int* search_array, int item, int start, int end) {
    int left=start,right=end,middle;
    
    //value smaller than entire array
    if (item < search_array[start]) {
        return -1;
    }
    
    //value larger than entire array
    if (item >= search_array[end-1]) {
        return end-1;
    }
    
    //binary search
    while (right-left>1) {
        middle = left + (right-left)/2;
        if (search_array[middle] <= item) {
           left=middle;
        } else {
           right=middle;
        }
    } 
    
    //exact match
    if (search_array[left]==item) {
        return left;
    }
    //value in between numbers
    if (search_array[left] < item && item < search_array[left+1]) {
        return left;
    }
}
