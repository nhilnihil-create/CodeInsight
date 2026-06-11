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
    ll n,m,k;
    cin >> n >> m >> k;
    for(ll i = 0; i <= n;i++){
        for(ll j = 0;j <= m;j++){
            if(i*(m - j) + (n - i)*j == k){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}