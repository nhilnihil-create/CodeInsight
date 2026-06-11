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

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    ll now1 = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            now1 += abs(1-(sum+a[i])) * (sum+a[i] <= 0);
            sum = max(1LL, sum+a[i]);
        }else{
            now1 += abs(-1-(sum+a[i])) * (sum+a[i] >= 0);
            sum = min(-1LL, sum+a[i]);
        }
    }
    ll now2 = 0; sum = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 1){
            now2 += abs(1-(sum+a[i])) * (sum+a[i] <= 0);
            sum = max(1LL, sum+a[i]);
        }else{
            now2 += abs(-1-(sum+a[i])) * (sum+a[i] >= 0);
            sum = min(-1LL, sum+a[i]);
        }
    }
    cout << min(now1, now2) << endl;
}