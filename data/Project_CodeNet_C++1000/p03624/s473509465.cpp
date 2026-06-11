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
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> ab;
    rep(i, n) ab[s[i]]++;

    for (char c = 'a'; c <= 'z'; c++) {
        if (ab[c] == 0) {
            cout << c << endl;
            exit(0);
        }
    }

    cout << "None" << endl;
    return 0;
}