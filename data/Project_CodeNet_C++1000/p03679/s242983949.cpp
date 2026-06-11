#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int x, a, b; cin >> x >> a >> b;
    if (a >= b) {
        cout << "delicious" << endl;
    } else if (b - a <= x) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
    return 0;
}