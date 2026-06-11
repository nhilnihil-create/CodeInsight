#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MOD = (int)1e9 + 7;

template<typename T = char>
vector<pair<T, int>> run_length_encode(string &a) {
    vector<pair<T, int>> res;
    for (T &ai: a) {
        if (res.empty() || res.back().first != ai) res.emplace_back(ai, 1);
        else res.back().second++;
    }
    return res;
}

int main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    auto rle = run_length_encode(s);
    long long ans = 3 * rle[0].second;
    for (int i = 0; i + 1 < (int)rle.size(); i++) {
        int a = rle[i].second, b = rle[i + 1].second;
        if (a == 1 && b == 1) ans *= 2;
        if (a == 1 && b == 2) ans *= 2;
        if (a == 2 && b == 1) ans *= 1;
        if (a == 2 && b == 2) ans *= 3;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
