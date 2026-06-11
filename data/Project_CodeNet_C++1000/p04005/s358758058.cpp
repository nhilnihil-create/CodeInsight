#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a%2 == 0 || b%2 == 0 || c%2 == 0)cout << 0 << endl;
    else {
        vector<ll>abc = {a,b,c};
        sort(all(abc));
        cout << abc[0] * abc[1] << endl;
    }
}