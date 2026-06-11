#include <bits/stdc++.h>
using namespace std;

int solve(int p, const vector<vector<int>> &v) {
    if (v.at(p).size() == 0) return 0;

    int len = (int)v.at(p).size();
    vector<int> res(len);
    for (int i = 0; i < len; i++) {
        res.at(i) = solve(v.at(p).at(i), v);
    }
    sort(res.begin(), res.end());

    int maximum = 0;
    for (int i = 0; i < len; i++) {
        maximum = max(maximum, res.at(i) + len - i);
    }

    return maximum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        a--;
        v.at(a).push_back(i + 1);
    }

    int ans = solve(0, v);
    cout << ans << endl;
}