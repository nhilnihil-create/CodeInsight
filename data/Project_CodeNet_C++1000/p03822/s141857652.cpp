#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int f(const vector<vector<int>> &g,int s){
    int t = g[s].size();
    int ans = 0;
    if(t==0) return ans;
    priority_queue<int> q;
    auto ite = g[s].begin();
    for(int i = 0; i < t; i++){
        q.push(f(g,*ite));
        ite++;
    }
    int cnt = 1;
    while(!q.empty()){
        int s = q.top();
        q.pop();
        chmax(ans,s+cnt);
        cnt++;
    }
    return ans;
}

int main() {
    int N;
    cin>>N;
    vector<vector<int>> g(N);
    for(int i = 1;i < N; i++){
        int x;
        cin>>x;
        g[x-1].push_back(i);
    }
    cout<<f(g,0)<<endl;
}