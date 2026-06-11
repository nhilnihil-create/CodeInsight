//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int64_t gcd(int64_t a, int64_t b) {return b?gcd(b, a%b):a;}
int64_t lcm(int64_t a, int64_t b) {return a/gcd(a,b)*b;}

int main() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    sort(rall(a));

    int g=a[0];
    rep(i, n) {
        g = gcd(g, a[i]);
    }

    if(k%g || k > a[0]) cout << "IMPOSSIBLE" << endl;
    else cout << "POSSIBLE" << endl;
}