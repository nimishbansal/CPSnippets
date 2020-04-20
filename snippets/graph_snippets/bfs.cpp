#include<bits/stdc++.h>
using namespace std;
const int mxN = 100000;
int level[1 + mxN];
int visited[1 + mxN];
int parent[1 + mxN];
vector<int>* adj;
void bfs(int source){
    memset(level, -1, sizeof(level));
    memset(visited, false, sizeof(visited));
    memset(parent, false, sizeof(parent));
    queue<int> mp;
    mp.push(source);
    visited[source] = true;
    level[source] = 0;
    while(!mp.empty()){
        int u = mp.front();
        mp.pop();
        for(auto v: adj[u]){
            if (visited[v]) continue;
            else{
                visited[v] = true;
                mp.push(v);
                level[v] = level[u] + 1;
                parent[v] = u;
            }
        }
    }
}

int main(){

}
