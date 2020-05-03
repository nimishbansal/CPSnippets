#include<bits/stdc++.h>
using namespace std;


int BITOperation(int a, int b){
    // returns the result of operation between the nodes;
    return a + b;
}

int getDefaultValue(){
    // returns the default value if there is no node
    // for.e.g in case of addition it is equal to 0
    // in case of multiplication it is 1
    return 0;
}

int query_BIT(int BITree[], int index){
    // returns result of arr[0:index]

    index = index + 1;
    // travelling all ancestors
    int answer = getDefaultValue();
    while(index > 0){
        // cout << "adding value " << BITree[index] << endl;
        answer = BITOperation(answer, BITree[index]);
        index -= (index & -index);
    }
    return answer;

}

void update_BIT(int BITree[], int index, int value, int n){
    // index passed in parameter is 0 based
    // but in BIT array it is 1 based

    // apply given operation at index 'index'
    // with given value
    // for e.g. addtition BITree[index] += value

    index = index + 1;
    // travelling all ancestors
    while(index <= n){
        BITree[index] = BITOperation(BITree[index], value);
        index += (index & -index);
    }

}

void construct_BIT(int BITree[], int arr[], int n){
    for(int i = 0 ; i  < n; i++){
        update_BIT(BITree, i, arr[i], n);
    }
}
int main(){
    int arr[10] = {2, 5, 7, 8, 9, 12, 13, 14, 15, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int BITree[n + 1];
    memset(BITree, getDefaultValue(), sizeof(BITree));
    construct_BIT(BITree, arr, n);
    cout << "Prefix sum for array 0 to 4 = " << query_BIT(BITree, 9) << endl;
    update_BIT(BITree, 0, 2, n); // adding 2 to arr[0]
    update_BIT(BITree, 1, 4, n); // adding 4 to arr[1]
    cout << "Prefix sum for array 0 to 4 = " << query_BIT(BITree, 9) << endl;
    return 0;
}
