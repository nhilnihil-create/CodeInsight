#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    int g = gcd(a, b);
    if(c%g == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
