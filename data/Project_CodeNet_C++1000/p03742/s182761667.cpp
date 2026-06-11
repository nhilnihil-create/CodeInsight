#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp fixed << setprecision
#define pb(x) push_back(x)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    ll X, Y;
    cin >> X >> Y;
    if(abs(X-Y) <= 1) cout << "Brown" << endl;
    else cout << "Alice" << endl;
}