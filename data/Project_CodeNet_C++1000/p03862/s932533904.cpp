#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;
 
 
int main() {
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans =0;
    for(int i = 1;i<n;++i){
        if(a[i]+a[i-1]<=x){
            continue;
        }
        else if(a[i]+a[i-1]>x&&a[i-1]>x){
            ans += a[i];
            a[i]=0;
            ans+=a[i-1]-x;
        }
        else if (a[i]+a[i-1]>x&&a[i-1]<=x){
            ans+=a[i]+a[i-1]-x;
            a[i]=x-a[i-1];    
        }
    }
    cout << ans << endl;
}
