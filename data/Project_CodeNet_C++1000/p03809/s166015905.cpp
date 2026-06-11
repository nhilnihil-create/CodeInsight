#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
const int inf = 1 << 30;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
ll A[100010];
vector<int> G[100010];
bool flag = true;
bool used[100010];

ll dfs(int v){
    used[v] = true;

    ll l = 0, r = 0;
    int son = 0;
    ll mx = 0;
    for(auto& u : G[v]){
        if(used[u]) continue;
        son++;
        ll val = dfs(u);
        chmax(mx, val);
        r += val;
    }
    if(son == 0) return A[v];
    else if(son == 1){
        if(r != A[v]) flag = false;
        return A[v];
    }else{
        l = max((r + 1) / 2, mx);
        if(A[v] < l || r < A[v]) flag = false;
        return A[v] * 2 - r;
    }
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    int p = 1;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        if(G[a].size() == 1) p = a;
        if(G[b].size() == 1) p = b;
    }
    if(dfs(p) != A[p]) flag = false;
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}