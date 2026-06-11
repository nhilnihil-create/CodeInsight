#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    rep(i, N) {
        if (s[i] != t[cnt]) cnt = 0;
        if (s[i] == t[cnt]) ++cnt;
    }
    cout << 2 * N - cnt << endl;
}