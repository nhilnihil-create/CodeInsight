#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;
 
 
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    bool ok = true;
    if(n%2==1){
        if(a[0]!=0) {
            cout << 0 << endl;
            return 0;
        }
        for(int i = 1 ;i<n-1;i+=2){
            if(a[i]!=a[i+1]){
            cout << 0 << endl;
            return 0;
            }           
        }
    }
    if(n%2==0){
        for(int i = 0;i<n-1;i+=2){
            if(a[i]!=a[i+1]){
                cout << 0 << endl;
            return 0;
        }
    }
    }
    ll ans=1;
    ll mod = 1000000007;
    if(ok) {
        rep(i,n/2){
            ans *=2;
            ans %=mod;
        }
        cout << ans <<endl;
        return 0;
    }
    else cout << 0 << endl;
    return 0;
}