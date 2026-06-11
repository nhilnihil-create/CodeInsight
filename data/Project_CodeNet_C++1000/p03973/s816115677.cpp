#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ans += a[0]-1;
    ll p = 2;
    for(int i=1;i<n;i++){
        ll cnt = (a[i]-1)/p;
        ans += cnt;
        if(a[i] == p) p++;
    }
    cout << ans << endl;
    return 0;
}