#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    string t;
    int n = (s.size() - 1) / 2;
    rep(i, n + 1) {
        t.push_back(s[2 * i]);
    }
    cout << t << endl;
    return 0;
}