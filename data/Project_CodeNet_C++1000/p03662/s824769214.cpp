#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
#define ll long long

vector<int> Map[maxn];

int ans[4],vis[maxn];

void bfs(int a,int b){
    vis[a] = 1;
    vis[b] = 2;
    queue<int> q;
    q.push(a);
    q.push(b);
    while (!q.empty()){
        int x = q.front();
        ans[vis[x]]++;
        q.pop();
        for(int i=0;i<Map[x].size();i++){
            if(vis[Map[x][i]]) continue;
            vis[Map[x][i]] = vis[x];
            q.push(Map[x][i]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n,a,b;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        Map[a].push_back(b);
        Map[b].push_back(a);
    }
    bfs(1,n);
    if(ans[1]>ans[2])  cout<<"Fennec"<<endl;
    else               cout<<"Snuke"<<endl;
    return 0;
}
