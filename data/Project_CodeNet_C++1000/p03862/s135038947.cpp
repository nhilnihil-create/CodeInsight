#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    if(a[0] > x){
        ans += a[0] - x;
        a[0] = x;
    } 
    for(int i = 0; i < n-1; ++i){
        if(a[i] + a[i+1] > x){
            ans += (a[i] + a[i+1]) - x;
            a[i+1] -= (a[i] + a[i+1]) - x;
        }
    }
    cout << ans << endl;
}