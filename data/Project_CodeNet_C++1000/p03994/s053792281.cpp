#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int k;
    cin >> k;

    vector<int> c(s.size());
    rep(i, s.size()) c[i] = 'z' - s[i] + 1;

    rep(i, s.size() - 1) {
        if (k >= c[i] && s[i] != 'a') {
            s[i] = 'a';
            k -= c[i];
        }
    }

    s[s.size() - 1] = (s[s.size() - 1] - 'a' + k) % 26 + 'a';

    cout << s << endl;
}