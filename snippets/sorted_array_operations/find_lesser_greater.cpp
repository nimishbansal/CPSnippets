#include<bits/stdc++.h>
using namespace std;
#define UNDEFINED -3
int bisect_left(int arr[], int x, int size, int lo=0, int hi=UNDEFINED){
    /*
        Return the index where to insert item x in list arr,
        assuming arr is sorted.
    */

    if (lo < 0){
        cout << "lo must be non-negative";
        return 0;
    }
    if (hi == UNDEFINED)
        hi = size;
    while (lo < hi){
        int mid = (lo+hi)/2;
        if (arr[mid] < x){
             lo = mid+1;
        }
        else{
            hi = mid;
        }
    }
    return lo;
}

int bisect_right(int arr[], int x, int size, int lo=0, int hi=UNDEFINED){
    /*
        Return the index where to insert item x in list arr,
        assuming arr is sorted.
    */

    if (lo < 0){
        cout << "lo must be non-negative";
        return 0;
    }
    if (hi == UNDEFINED)
        hi = size;
    while (lo < hi){
        int mid = (lo+hi)/2;
        if (x < arr[mid]){
             lo = mid+1;
        }
        else{
            hi = mid;
        }
    }
    return lo;
}


int get_index(int arr[], int x, int& answer_index, int size){
    /*Locate the index of leftmost value exactly equal to x*/
    int i = bisect_left(arr, x, size);
    if ((i != size) && (arr[i] == x)){
        answer_index = i;
        return true;
    }
    return false;
}

bool find_gt(int arr[], int x, int& answer_index, int size){
    /*Find index of leftmost item greater than x*/
    int i = bisect_right(arr, x, size);
    if (i != size){
        answer_index = i;
        return true;
    }
    return false;
}

bool find_gte(int arr[], int x, int& answer_index, int size){
    /*Find index of leftmost item greater than or equal to x*/
    int i = bisect_left(arr, x, size);
    if (i != size){
        answer_index = i;
        return true;
    }
    return false;
}

bool find_lt(int arr[], int x, int& answer_index, int size){
    /*Find index of leftmost item less than x*/
    int i = bisect_left(arr, x, size);
    if (i){
        answer_index = i - 1;
        return true;
    }
    return false;
}

bool find_lte(int arr[], int x, int& answer_index, int size){
    /*Find index of leftmost item less than or equal to x*/
    int i = bisect_right(arr, x, size);
    if (i){
        answer_index = i - 1;
        return true;
    }
    return false;
}

int main(){
    return 0;
}
