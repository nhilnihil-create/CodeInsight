#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const ll MAX = 1e9+7;

void solve(){
    ll w, a, b; cin>>w>>a>>b;
    ll res = max(max(a, b) - (min(a, b)+w), 0*1ll);
    cout<<res<<endl;
}

int main(){
    solve();
    Bye;
}