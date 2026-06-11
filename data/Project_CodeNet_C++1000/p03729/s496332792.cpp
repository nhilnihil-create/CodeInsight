#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int n, m, l;
    n = a.size();
    m = b.size();
    l = c.size();

    if(a[n-1] == b[0] && b[m-1] == c[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
}