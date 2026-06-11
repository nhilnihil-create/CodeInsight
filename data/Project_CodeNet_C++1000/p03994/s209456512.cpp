#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int dxx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 }, dyy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
    string s;
    int k;
    cin >> s >> k;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') continue;
        if ('z' - s[i] < k) {
            k -= ('z' - s[i] + 1);
            s[i] = 'a';
        }
    }
    if (k > 0) {
        s[s.size() - 1] = (s[s.size() - 1] - 'a' + k) % 26 + 'a';
    }

    cout << s << "\n";
}