#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<ll, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)1e5 + 9;
vector<int> T[N];
int k;
int res;

int dfs(int u){ 
    int ret;
    int mx = 0;
    for(auto x : T[u]){
        ret = dfs(x);
        if(u == 1){
            if(ret == k){
                res ++ ;
            }
        }
        else{
            if(ret + 1 == k){
                res ++ ;
            }
            else{
                mx = max(mx, ret + 1);
            }
        }
    }
    return mx;
    
}

int main(){
    fastIO;
    int n;
    cin >> n >> k;
    int p;
    cin >> p;
    if(p != 1)
        res ++ ;
    for(int i = 2; i <= n; i ++ ){
        cin >> p;
        T[p].push_back(i);
    }
    dfs(1);
    cout << res;
    return 0;
}