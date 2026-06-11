#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;
// int64_t INF = 9223372036854775807;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t q,h,s,d,n;
    cin >> q >> h >> s >> d >> n;
    n *= 1000;
    int64_t res = 0;
    if(d<2*s && d<4*h && d<8*q){
        res += (n/2000) * d;
        n -= 2000 * (n/2000);
    }
    if(s<2*h && s<4*q){
        res += (n/1000) * s;
        n -= 1000 * (n/1000);
    }
    if(h<2*q){
        res += (n/500) * h;
        n -= 500 * (n/500);
    }
    res += (n/250) * q;
    cout << res << endl;
}