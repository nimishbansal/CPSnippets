#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define len(a) (int)a.size()

template <typename KEY, typename VALUE>
bool find_gt(map<KEY, VALUE> mp, KEY x, KEY& answer_index){
    /*Find index of leftmost item in sorted map greater than x*/
    answer_index = -1;
    auto it = mp.upper_bound(x);
    if (it == mp.end()) return false;
    answer_index = (*it).first;
    return true;
}

template <typename KEY, typename VALUE>
bool find_gte(map<KEY, VALUE> mp, KEY x, KEY& answer_index){
    /*Find index of rightmost item in sorted map greater than  or equal to x*/
    answer_index = -1;
    auto it = mp.lower_bound(x);
    if (it == mp.end()) return false;
    answer_index = (*it).first;
    return true;
}

template <typename KEY, typename VALUE>
bool find_lte(map<KEY, VALUE> mp, KEY x, KEY& answer_index){
    /*Find index of rightmost item in sorted map less than or equal x*/
    answer_index = -1;
    auto it = mp.upper_bound(x);
    if (it == mp.begin()) return false;
    answer_index = (*--it).first;
    return true;
}

template <typename KEY, typename VALUE>
bool find_lt(map<KEY, VALUE> mp, KEY x, KEY& answer_index){
    /*Find index of leftmost item in sorted map less than x*/
    answer_index = -1;
    auto it = mp.lower_bound(x);
    if (it == mp.begin()) return false;
    answer_index = (*--it).first;
    return true;
}




int main(){
    faster;
    map<int, vector<int>> mp;
    mp[4].push_back(4);
    mp[6].push_back(20);
    mp[8].push_back(21);

    // 4 Different Test Cases 
    int answer_index;
    int val = 3;
    bool result1 = find_gt<int, vector<int>>(mp, val, answer_index);
    cout << result1 << " with index " << answer_index << endl;

    bool result2 = find_gte<int, vector<int>>(mp, val, answer_index);
    cout << result2 << " with index " << answer_index << endl;

    bool result3 = find_lt<int, vector<int>>(mp, val, answer_index);
    cout << result3 << " with index " << answer_index << endl;

    bool result4 = find_lte<int, vector<int>>(mp, val, answer_index);
    cout << result4 << " with index " << answer_index << endl;

    return 0;
}
