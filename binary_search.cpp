/*binary search to find right index boundary x equal to or smaller than value t
  x such that A[x] <= t, A[x+1] > t)
*/

#include <iostream>

using namespace std;
int binary_search(int* search_array, int item, int start, int end); 

int main(void) {
    int test[10]={1,1,2,2,4,4,4,6,6,6};
    
    cout << binary_search(test,5,0,10) << endl;
    
    return 0;
}

int binary_search(int* search_array, int item, int start, int end) {
    int left=start,right=end,middle;
    while (right-left>1) {
        middle = left + (right-left)/2;
        if (search_array[middle] <= item) {
           left=middle;
        } else {
           right=middle;
        }
    } 
    if (search_array[left]==item || 
        (search_array[left] < item && item < search_array[left+1]) ) {
        return left;
    } else {
        return -1;
    }
        
}
