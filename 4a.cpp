#include<bits/stdc++.h>
using namespace std;
const int mxN = 1000000;
long long dp[1 + mxN][4];
long long ctr = 0;
const int A = 2;
const int A_BAR = 3;
long long mod = 998244353;
class Node{
    static int x;
public:
    char ch;
    Node* left;
    Node* right;
    int id;
    Node(char c){
        ch = c;
        left = NULL;
        right  = NULL;
        id = ++ctr;
    }

};
map<char, map<int, vector<pair<int, int>>>> mp_global;

void insertAND(map<int, vector<pair<int, int>>>& mp_op){
    // 0
    mp_op[0].push_back({0, 0});
    mp_op[0].push_back({0, 1});
    mp_op[0].push_back({0, A});
    mp_op[0].push_back({0, A_BAR});
    mp_op[0].push_back({1, 0});
    mp_op[0].push_back({A, 0});
    mp_op[0].push_back({A, A_BAR});
    mp_op[0].push_back({A_BAR, 0});
    mp_op[0].push_back({A_BAR, A});

    // 1
    mp_op[1].push_back({1, 1});

    // A
    mp_op[A].push_back({1, A});
    mp_op[A].push_back({A, 1});
    mp_op[A].push_back({A, A});

    // A Bar
    mp_op[A_BAR].push_back({1, A_BAR});
    mp_op[A_BAR].push_back({A_BAR, 1});
    mp_op[A_BAR].push_back({A_BAR, A_BAR});

}
void insertOR(map<int, vector<pair<int, int>>>& mp_op){
    // 0
    mp_op[0].push_back({0, 0});


    // 1
    mp_op[1].push_back({0, 1});
    mp_op[1].push_back({1, 0});
    mp_op[1].push_back({1, 1});
    mp_op[1].push_back({1, A});
    mp_op[1].push_back({1, A_BAR});
    mp_op[1].push_back({A, 1});
    mp_op[1].push_back({A, A_BAR});
    mp_op[1].push_back({A_BAR, 1});
    mp_op[1].push_back({A_BAR, A});

    // A
    mp_op[A].push_back({0, A});
    mp_op[A].push_back({A, 0});
    mp_op[A].push_back({A, A});

    // A Bar
    mp_op[A_BAR].push_back({0, A_BAR});
    mp_op[A_BAR].push_back({A_BAR, 0});
    mp_op[A_BAR].push_back({A_BAR, A_BAR});

}
void insertXOR(map<int, vector<pair<int, int>>>& mp_op){
    // 0
    mp_op[0].push_back({0, 0});
    mp_op[0].push_back({1, 1});
    mp_op[0].push_back({A, A});
    mp_op[0].push_back({A_BAR, A_BAR});

    // 1
    mp_op[1].push_back({0, 1});
    mp_op[1].push_back({1, 0});
    mp_op[1].push_back({A, A_BAR});
    mp_op[1].push_back({A_BAR, A});

    // A
    mp_op[A].push_back({0, A});
    mp_op[A].push_back({1, A_BAR});
    mp_op[A].push_back({A, 0});
    mp_op[A].push_back({A_BAR, 1});


    // A_BAR
    mp_op[A_BAR].push_back({0, A_BAR});
    mp_op[A_BAR].push_back({1, A});
    mp_op[A_BAR].push_back({A_BAR, 0});
    mp_op[A_BAR].push_back({A, 1});

}
void createmap(map<char, map<int, vector<pair<int, int>>>>& mp){
    mp['&'] = map<int, vector<pair<int, int>>>();
    mp['|'] = map<int, vector<pair<int, int>>>();
    mp['^'] = map<int, vector<pair<int, int>>>();

    for (int i = 0; i <= 3; i++){
        mp['&'][i] = vector<pair<int, int>>();
        mp['|'][i] = vector<pair<int, int>>();
        mp['^'][i] = vector<pair<int, int>>();
    }
    insertAND(mp['&']);
    insertOR(mp['|']);
    insertXOR(mp['^']);

}


long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

long long modInverse(long long b, long long m)
{
    long long x, y; // used in extended GCD algorithm
    long long g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x%m + m) % m;
}


// Function to compute a/b under modlo m
long long modDivide(long long a, long long b, long long m)
{
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1){
        cout << "Division not defined";
        return -1;
    }
    else{}
       // cout << "Result of division is " << (inv * a) % m;

    return (inv * a) % m;
}


long long modexpo(long long x, long long n, long long m = mod){
    long long ret = 1%m;
    while(n){
        if(n&1) ret = ret * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ret;
}

void infix(Node* root){
    if (root->left != NULL){
        if (root -> left -> left != NULL || root -> left -> right !=  NULL){
            cout <<"(";
            infix(root->left);
            cout << ")";
        }
        else{
            infix(root->left);
        }

    }
    // root->id = ++ctr;
    cout << root -> ch;

    if (root->right != NULL){
        if (root -> right -> left != NULL || root -> right -> right !=  NULL){
            cout <<"(";
            infix(root -> right);
            cout << ")";
        }
        else{
            infix(root -> right);
        }
    }
}

bool isOperator(char c){
    bool result = (c == '^')? 1 : (c == '&') ? 1 : (c == '|') ? 1 : 0;
    return result;
}


long long solve(Node* root, int target){
    if (((root->left) == NULL) && ((root->right) == NULL)){
        // leaf node
        dp[root->id][target] = 1;
        return 1;
    }

    if (dp[root->id][target]!=-1){
        return dp[root->id][target] % mod;
    }
    // cout << "character = " << root-> ch << ", and target = " << target << endl;
    vector<pair<int,int>> possibilities = mp_global[root->ch][target];
    long long ans = 0;
    for(unsigned int i = 0 ; i < possibilities.size(); i++){
        // cout << "i = " << i << endl;
        int target_left = possibilities[i].first;
        int target_right = possibilities[i].second;
        // cout << target_left <<" " << target_right << endl;
        long long ans_left = solve(root->left, target_left)%mod;
        long long ans_right = solve(root->right, target_right)%mod;
        long long curr_ans = (ans_left * ans_right) % mod;
        // cout << "answer for above = " << curr_ans << endl;
        ans = (ans + (curr_ans)) % mod;
    }
    return dp[root->id][target] = ans % mod;
}

void print(stack<Node*> st){
    if (st.empty()){
        return;
    }
    cout << st.top() <<" ";
    st.pop();
    print(st);
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    freopen("tc.txt", "r", stdin);
    createmap(mp_global);
    // cout << modDivide(20, 50, mod) << endl;
    // cout << ((20 % mod) * modInverse(50, mod))% mod << endl;
    // cout << modInverse(modexpo(4, 2500000, mod), mod) << endl;
    int t;
    cin >> t;
    while(t--){
        string expr;
        cin >> expr;
        // string expr = "((#|#)&((#^#)&#))";
        // expr = "(#^#)";
        // expr = "(#&#)";
        // string expr = "#";
        stack<Node*> st;
        stack<char> operators;
        for (auto c: expr){
            if (isOperator(c)){
                operators.push(c);
            }
            else{
                Node* n = new Node(c);
                st.push(n);
            }
            if (c == ')'){
                    st.pop(); // pop closing bracket
                    Node* n2 = st.top();
                    st.pop();
                    Node* n1 = st.top();
                    st.pop();
                    char op = operators.top();
                    operators.pop();
                    Node * resultingNode = new Node(op);
                    resultingNode -> left = n1;
                    resultingNode -> right = n2;
                    st.pop(); //pop opening bracket
                    st.push(resultingNode);
            }
        }
        Node* root = st.top();
        // Node *rootClone = root;
        st.pop();
        // cout <<"(";
        // infix(rootClone);
        // return 0;

        // cout <<")";
        // cout << endl;
        // cout << root->id << endl;
        long long ans0 = solve(root, 0);
        long long ans1 = solve(root, 1);
        long long ans_a = solve(root, A); //a
        long long ans_a_bar = solve(root, A_BAR); //A_BAR
        // cout << ans0 << endl;
        // cout << ans1 << endl;
        // cout << ans_a << endl;
        // cout << ans_a_bar << endl;
        long long count = 0;

        for (unsigned int i = 0; i < expr.size(); i++)
        {
           if (expr.at(i) == '#')
               count++;
        }
        // cout << "count = " << count << endl;
        // int co = count(expr.begin(), expr.end(), "#");
        // cout << "co =" << co << endl;
        // long long co = 1;
        // cout << ans0 << endl;
        // modInverse(modexpo(4, 2500000, mod), mod)

        cout << (ans0 * (modInverse(modexpo(4, count, mod), mod) % mod))%mod << " ";
        cout << (ans1 * (modInverse(modexpo(4, count, mod), mod) % mod))%mod << " ";
        cout << (ans_a * (modInverse(modexpo(4, count, mod), mod) % mod))%mod << " ";
        cout << (ans_a_bar * (modInverse(modexpo(4, count, mod), mod) % mod))%mod << endl;

        // cout << ans0 << " " << ans1 << " " << ans_a <<" " << ans_a_bar << endl;
        // cout << modDivide(ans0, pow(4, count), mod) << " ";
        // cout << modDivide(ans1, pow(4, count), mod) << " ";
        // cout << modDivide(ans_a, pow(4, count), mod) << " ";
        // cout << modDivide(ans_a_bar, pow(4, count), mod) << "\n";// << " ";
    }
    return 0;
}
