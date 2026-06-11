#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 2005;
vector<int> T[N];
int dist[N];

int n, k;
int solve(vector<int> st, int d){
    for(int i = 1; i <= n; i ++ )
        dist[i] = 123141;
    queue<int> ff;
    for(auto x : st){
        ff.push(x);
        dist[x] = d;
    }
    int node;
    while(!ff.empty()){
        node = ff.front();
        ff.pop();
        for(auto x : T[node]){
            if(dist[node] + 2 < dist[x]){
                dist[x] = dist[node] + 2;
                ff.push(x);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i ++ ){
        if(dist[i] > k){
            res ++ ;
        }
    }
    return res;
}

int main(){
    fastIO;
    cin >> n >> k;
    int res = 123141;
    int u[n], v[n];
    for(int i = 1 ;i < n ; i ++ ){
        cin >> u[i] >> v[i];
        T[u[i]].push_back(v[i]);
        T[v[i]].push_back(u[i]);
    }
    for(int i = 1; i <= n; i ++ )
        res = min(res,solve({i},0));
    for(int i = 1; i < n ; i ++ )
        res = min(res,solve({u[i],v[i]}, 1));
    cout << res << "\n";
    return 0;
}
