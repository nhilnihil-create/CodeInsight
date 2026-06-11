#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;
constexpr double EPS = 1e-10;
#pragma endregion

void solve() {
    int h, w;
    cin >> h >> w;
    vector<int> cnt(26);
    for (int i=0; i<h; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            cnt.at(c-'a')++;
        }
    }
    bool odd = false;
    int cnt2 = 0, cnt4 = 0;
    for (int i=0; i<26; i++) {
        if (cnt.at(i)%2 != 0) {
            if (odd) {
                cout << "No" << "\n";
                return;
            } else {
                odd = true;
                cnt.at(i)--;
            }
        }
        if (cnt.at(i)%4 == 0) {
            cnt4++;
        } else if (cnt.at(i)%2 == 0) {
            cnt2++;
        }
    }
    if (h%2 != 0 && w%2 != 0) {
        if (odd && cnt2 <= h/2 + w/2) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    } else if (h%2 == 0 && w%2 == 0) {
        if (odd || cnt2 > 0) cout << "No" << "\n";
        else cout << "Yes" << "\n";
    } else {
        int tmp = (h%2 == 0) ? h/2 : w/2;
        if (odd || cnt2 > tmp) cout << "No" << "\n";
        else cout << "Yes" << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
