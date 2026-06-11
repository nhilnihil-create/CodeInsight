#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll n;
    cin >> n;
    P a[n];
    rep(i,n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a,a+n);
    ll ans = 0;
    set<ll> s;
    s.insert(n); s.insert((ll)-1);
    for(ll i = 0; i < n; i++){
        s.insert(a[i].second);
        auto itr = s.find(a[i].second);
        auto jtr = s.find(a[i].second); 
        itr++; jtr--;
        ans += (*itr-a[i].second)*(a[i].second-*jtr)*(i+1);
    }
    cout << ans << endl;
    return 0;
}