#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

int main(){
    ll n;
    cin >> n;
    vector<pll> a(n);
    rep(i,n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());
    ll ans = 0;
    set<ll> st;
    st.insert(-1);
    st.insert(n);
    rep(i,n){
        auto it = st.lower_bound(a[i].second);
        ll res = a[i].first * ((*it) - a[i].second);
        --it;
        res *= (a[i].second - (*it));
        ans += res;
        st.insert(a[i].second);
    }
    cout << ans << endl;
    return 0;
}