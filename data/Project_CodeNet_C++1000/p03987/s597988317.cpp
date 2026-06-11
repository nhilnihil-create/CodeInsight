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
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n), pos(n+1);
    set<ll> st;
    rep(i, n){
        cin >> a[i];
        pos[a[i]] = i+1;
    }
    st.insert(pos[1]);
    ans += pos[1]*(n-pos[1]+1);
    REP(i, n-1){
        auto tmp = st.upper_bound(pos[i+1]);
        ll l, r;
        if(tmp == st.begin()){l = 0; r = *tmp;}
        else if(tmp == st.end()){tmp--; l = *tmp; r = n+1;}
        else{tmp--; l = *tmp; tmp++; r = *tmp;}
        l++; r--;
        int a = pos[i+1];
        ans += (a-l+1) * (r-a+1) * (i+1);
        st.insert(pos[i+1]);
    }
    cout << ans << endl;
}
