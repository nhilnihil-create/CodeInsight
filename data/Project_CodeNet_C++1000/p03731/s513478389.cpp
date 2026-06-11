#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, T; cin >> n >> T;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    ll ans = 0;
    rep(i,n-1){
        if(t[i+1] - t[i] > T) ans += T;
        else ans += t[i+1] - t[i];
    }
    ans += T;
    cout << ans << endl;
}