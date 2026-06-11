#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int Plus_or_Minus(int a){
    if(a < 0)return -1;
    if(a == 0)return 0;
    return 1;
}

int main() {
    ll n, k, num = 0, ans = 0;
    cin >> n >> k; k--;
    vector<ll> a(n), sum(n, 0), rsum(n, 0);
    rep(i, n)cin >> a[i]; a.push_back(0);
    rep(i, n){sum[i] = a[i] * (a[i] > 0); if(i)sum[i] += sum[i-1];}
    reverse(all(a));
    rep(i, n){rsum[i] = a[i] * (a[i] > 0); if(i)rsum[i] += rsum[i-1];}
    reverse(all(a));
    reverse(all(rsum));
    ll l = 0, r = a[k];
    rep(i, k)num += a[i];
    for(int i = k-1; i < n; i++){
        ll now = 0;
        if(i-k-1 >= 0)now += sum[i-k-1];
        if(i+1 < n)now += rsum[i+1];
        if(i == k-1){
            if(Plus_or_Minus(r) == 0)now += max(0LL, num);
            else now += max(0LL, r+num);
        }else if(i == n-1){
            num += a[i] - a[i-k];
            l = a[i-k];
            if(Plus_or_Minus(l) == 0)now += max(0LL, num);
            else now += max(0LL, l+num);
        }else{
            num = num + a[i] - a[i-k];
            l = a[i-k];
            r = a[i+1];
            if(Plus_or_Minus(l) == Plus_or_Minus(r) && Plus_or_Minus(l) != 0){
                now += max({0LL, num + max({l, r, l+r}), max(l, r)});
            }
            else{
                now += max(0LL, num) + max(0LL, l) + max(0LL, r);
            }
        }
        chmax(ans, now);
    }
    cout << ans << endl;
}
