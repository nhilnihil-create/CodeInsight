#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    int n = s.size();

    rep(i, n) {
        char c = s[i];
        int pos = c - 'a';
        if (c == 'a') continue;
        if (26 - pos <= k) {
            s[i] = 'a';
            k -= 26 - pos;
        }
    }

    char c = s[n-1];
    int pos = c - 'a';
    k -= 26 - pos;
    k = ((k % 26) + 26) % 26;
    s[n-1] = 'a' + k;

    cout << s << endl;
    return 0;
}
