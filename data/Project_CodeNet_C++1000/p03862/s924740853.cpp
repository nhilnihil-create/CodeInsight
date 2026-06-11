#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    ll n, x, ans = 0;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    rep(i, n-1){
        if(a[i]+a[i+1] > x){
            if(a[i]+a[i+1]-x <= a[i+1]){
                ans += a[i]+a[i+1]-x;
                a[i+1] -= a[i]+a[i+1]-x;
            }
            else{
                ans += a[i+1];
                a[i+1] = 0;
                ans += a[i]-x;
                a[i] -= a[i]-x;  
            }
        }
    }
    cout << ans << endl;
}
