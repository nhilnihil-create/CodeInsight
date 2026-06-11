#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n,m;
    cin >> n >> m;
    ll res = 0;
    if(n <= m/2){
        res = n + (m-2*n)/4;
    }else{
       //Sccを作ることにおいて、S > 2*cならばそれより多くSを作ることは必要ない
       //だからc/2でいい
       res = m / 2;
    }
    cout << res << endl;
    return 0;
}