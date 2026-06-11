#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;
ll n,dp[200005];
vector<ll>v[200005];
void go(ll x,ll par){
    for(int i=0; i<v[x].size(); i++){
        if(v[x][i] != par){
            go(v[x][i] , x);
            dp[x] ^= dp[v[x][i]] + 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    
    go(1 , 0);
    
    if(dp[1])
        cout << "Alice";
    else
        cout << "Bob";
    
    
    return 0;
}
