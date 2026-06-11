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
    // 入力
    Init();
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // 各結び目iについて、a[i]+a[i-1]>=lとなる結び目があるかチェック
    bool ok = false;
    ll okIdx = -1;
    for(ll i=1; i<n; i++){
        // 条件を満たす結び目がある場合
        if(a[i]+a[i-1] >= l){
            ok = true, okIdx = i;
            break;
        }
    }
    
    // 条件を満たす結び目がある場合は、その結び目を残すように左右から解いていくことで達成可能
    if(ok){
        cout << "Possible" << endl;
        // 先頭から解いていく
        for(ll i=1; i<okIdx; i++) cout << i << endl;
        // 末尾から解いていく
        for(ll i=n-1; i>okIdx; i--) cout << i << endl;
        // 最後にl以上を満たしている結び目を解く
        cout << okIdx << endl;
    }
    // 条件を満たす結び目が無い場合は、達成不可能
    else cout << "Impossible" << endl;
}