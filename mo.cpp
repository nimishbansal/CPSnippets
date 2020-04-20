//mo comparator

int S;// block size
struct Query{
    int l, r;
};

bool cmp(Query A, Query B){
    if ((A.l/S)!=(B.l)/S) return A.l < B.l;
    return A.l / S % 2 ? A.r > B.r : A.r < B.r;
}


#include<bits/stdc++.h>
using namespace std;
int main(){
    return 0;
}
