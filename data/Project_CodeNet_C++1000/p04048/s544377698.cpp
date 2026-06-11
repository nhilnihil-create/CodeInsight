//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;

int64_t gcd(int64_t a, int64_t b) {return b?gcd(b, a%b):a;}
int64_t lcm(int64_t a, int64_t b) {return a/gcd(a,b)*b;}
int64_t extgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) { // ax+by=gcd(a, b)の解を与える
    int64_t d = a;
    if(b) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b)*x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

ll saiki(ll n, ll x) {
    if(n-x < x) x = n-x;
    if(x == 1) {
        return 3LL * (n-1);
    }
    return saiki(x + n%x, x) + (n/x-1) * x * 3LL;
} 

int main() {
    ll n, x;
    cin >> n >> x;

    ll ans = 1LL;
    ans *= gcd(n, x);
    n /= ans;
    x /= ans;

    cout << saiki(n, x) * ans << endl;
}