#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 最大公約数(ユークリッドの互除法)
// O(log max(a, b))
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << 3*(a-gcd(a, b)) << endl;
}