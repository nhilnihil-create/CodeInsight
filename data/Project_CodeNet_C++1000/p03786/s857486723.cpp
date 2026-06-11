#include <bits/stdc++.h>
#define endl "\n"
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    using ll = long long;
    ll n; cin >> n;
    vector<ll> a(n);

    // 最終的な大きさはsum, 合体する回数はn-1回
    for(ll i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end()); a.emplace_back(0);

    vector<ll> sum(n+1);
    vector<bool> chk(n+1, false);
    for(ll i=0; i<n; i++){
        sum[i] += a[i];
        sum[i+1] += sum[i];
        if(2*sum[i] >= a[i+1]) chk[i] = true;
    }
    ll ans = 0, pos = n-1;
    while(pos >= 0 && chk[pos]) ans++, pos--;
    cout << ans << endl;
}