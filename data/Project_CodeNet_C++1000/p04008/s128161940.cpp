#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 2e5 + 5;

int n ,k;
int a[maxn] , h[maxn];
vector<int> adj[maxn];
void DFS(int u , int par){
    for(int c : adj[u]){
        if(c == par)continue;
        h[c] = h[u] + 1;
        DFS(c , u);
    }
}
int res = 0;

int DFS1(int u , int par){
    int cur = 1;
    for(int c : adj[u]){
        if(c == par)continue;
        cur = max(cur , DFS1(c , u) + 1);
    }
    if(cur == k && u != 1)cur = 0 , res += par != 1;
    return cur;
}

int main(){
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    cin >> n >> k;
    res = 0;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        res += (a[i] != 1);
    }
    for(int i = 2 ; i <= n ; ++i){
        adj[a[i]].pb(i);
    }
    if(k == 1)return cout << res , 0;
    res = 0;
    DFS1(1 , 0);
    res += (a[1] != 1);
    cout << res;
}
