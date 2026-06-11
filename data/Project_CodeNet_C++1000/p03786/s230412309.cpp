#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    ll sum = 0;
    rep(i,n-1){
        sum += a[i];
        if(sum*2 >= a[i+1]) ++ans;
        else ans = 0;
    }
    ++ans;

    cout << ans << endl;
    return 0;
}
