#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n));

void fast() {

    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main() {
    fast();
    ll n,a,b;cin>>n>>a>>b;
    ll arr[n];
    for (int i = 0; i < n; ++i) {
    cin>>arr[i];
    }
    ll ans=0;
    for (int j = 0; j+1 <n ; ++j) {
        if((arr[j+1]-arr[j])*a<b)ans+=((arr[j+1]-arr[j])*a);
        else ans+=b;
    }
    cout<<ans;
}