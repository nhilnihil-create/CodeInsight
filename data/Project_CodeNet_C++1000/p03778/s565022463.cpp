#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int w, a, b;
    cin >> w >> a >> b;

    if (a >= b) {
        cout << max(0, a-b-w) << endl;
    }
    else {
        cout << max(0, b-a-w) << endl;
    }
    return 0;
}