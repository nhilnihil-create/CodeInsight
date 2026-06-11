#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    ll a[n];
    vector<ll> s(n+1,0);
    vector<ll> ps(n+1,0);
    rep(i,n) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
        if(a[i] > 0) ps[i+1] = ps[i] + a[i];
        else ps[i+1] = ps[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n-k+1; i++){
        ans = max(ans,ps[i-1]-ps[0]+max(s[i+k-1]-s[i-1],(ll)0)+ps[n]-ps[i+k-1]);
    }
    cout << ans << endl;
    return 0;
}