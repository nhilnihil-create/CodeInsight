#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
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

long long modPow(long long x, long long n, long long mod = MODV){
    if(n == 0) return 1;
    if(n%2 == 0) return modPow(x*x%mod, n/2, mod)%mod;
    return x%mod * modPow(x%mod, n-1, mod)%mod;
}

int main(){
    Init();
    ll n; cin >> n;
    // nが偶数だったら入力値は奇数、nが奇数だったら入力値は偶数でなければいけない
    ll chk = (n%2 == 0) ? 1 : 0;

    // 入力処理
    map<ll, ll> cnt;
    rep(i, n){
        ll in; cin >> in;
        cnt[in]++;
    }

    ll exp = 0;
    for(auto p: cnt){
        // 偶奇が一致しない場合はループから脱出
        if(p.first%2 != chk){ n = -1; break; }
        // 奇数長の場合で"0"の数が1以外の時はループから脱出、一致するなら無視
        else if(p.first == 0 && p.second != 1){ n = -1; break;}
        else if(p.first == 0 && p.second == 1){ continue; }
        // 2回以上同じ数字が出てきてもダメ
        else if(p.first != 0 && p.second != 2) { n = -1; break;}
        else exp++;
    }

    if(n == -1) cout << 0 << endl;
    else cout << modPow(2, exp, MODV) << endl;
}