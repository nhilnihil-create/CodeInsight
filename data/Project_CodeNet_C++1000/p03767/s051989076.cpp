#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n;  cin >> n;
    n *= 3;

    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<ll>());

    ll ans(0);
    for(int i=0;i<n/3;i++){
        ans += a[2*i+1];
    }

    cout << ans << endl;

    return 0;
}