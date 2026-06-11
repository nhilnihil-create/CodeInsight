#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> a;
    rep(i, 3*n) {
        ll t;cin>>t;
        a.push_back(t);
    }
    sort(all(a));
    ll ans = 0;
    for(ll i=n; i<3*n; i+=2){
        ans += a[i];
    }
    cout<<ans<<endl;
    return 0;
}