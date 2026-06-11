/**
*	created: 23.08.2020 15:49:26
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
using ll = long long;
using P = pair<int,int>;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b; cin >> a >> b;
    if (a % 3 == 0 || b % 3 == 0) cout << 0 << endl;
    else {
        vector<int> c;
        c.push_back(a);
        c.push_back(b);
        auto f = [](int x, int y) {
            int ret = INF;
            rep2(i,1,y) {
                int up = x * i, res = x * (y - i);
                int d = x/2;
                int r1 = (y - i) * d, r2 = (y - i) *  (x - d);
                int mx = max({up,r1,r2});
                int mn = min({up,r1,r2});
                chmin(ret,mx-mn);
            }
            return ret;
        };
        c.push_back(f(a,b));
        c.push_back(f(b,a));
        sort(all(c));
        cout << c[0] << endl;
    }
    return 0;
}