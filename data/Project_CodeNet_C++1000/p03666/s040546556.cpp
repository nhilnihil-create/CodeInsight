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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    // 左からi番目のマスの数値をx_iとし、y_i = x_i+1 - x_iとする。
    // 制約より、-d <= y_i <= -c or c <= y_i <= d とかける。
    // sum(y_i) = sum(x_i+1 - x_i) = x_n-1 - x_0 = b - a
    // 上記(1)を満たすy_iが存在すれば、条件を満たすx_iも存在するといえる。

    // -d <= y_i <= cとなるiがm個、c <= y_i <= dとなるiがn-1-m個あるとして、
    // (n-1-m)c - md <= sum(y_i) = b - a <= (n-1-m)d - mc
    // が成り立つmが1つでもあれば、条件を満たす数列の作成が可能である。
    const ll diff = b - a;
    for(ll i=0; i<n; i++){
        if(((n-1-i)*c - i*d <= diff) && (diff <= (n-1-i)*d - i*c)){
            YES();
            return 0;
        }
    }
    NO();
}