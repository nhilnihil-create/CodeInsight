#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF (1<<18)


int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];

    int ans = 0;
    rep(i,n){
        if(i == a[a[i]-1]-1) ans++;
        
    }

    cout<<ans/2<<endl;

    return 0;
}