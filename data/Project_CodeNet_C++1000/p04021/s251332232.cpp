#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<62) // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n;
    cin >> n;
    vi a(n), ao, ae;
    rep(i, n){
        cin >> a[i];
        i%2 == 0 ? ae.emplace_back(a[i]) : ao.emplace_back(a[i]);
    }

    // 最適な位置の偶奇
    sort(all(a));
    map<ll, ll> pos;
    rep(i, n) pos[a[i]] = i%2;

    // 元々偶数番目にあるものと奇数番目にあるものを独立してソート
    sort(all(ao));
    sort(all(ae));
    vi aSyn;
    rep(i, ao.size()){
        aSyn.emplace_back(ae[i]);
        aSyn.emplace_back(ao[i]);
    }
    if(ae.size() > ao.size()) aSyn.emplace_back(*ae.rbegin());

    // 接触する2要素について、本来あるべき偶奇の位置が異なっていればカウント
    vi ans(2, 0);
    for(ll i=0; i<aSyn.size(); i++){
        if(i%2 != pos[aSyn[i]]) ans[i%2]++;
    }
    cout << max(ans[0], ans[1]) << endl;
}