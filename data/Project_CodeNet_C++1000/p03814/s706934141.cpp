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
    string s; cin >> s;
    int l = MAX;
    int r = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') chmin(l, i);
        if (s[i] == 'Z') chmax(r, i);
    }

    cout << r - l + 1 << endl;
    return 0;
}