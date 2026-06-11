#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    int n, x;
    cin >> n >> x;
    int size = 2 * n - 1;
    if ((x == 1) || (x == size)) {
        cout << "No" << endl;
        return 0;
    }
    set<int> s;
    rep(i, size) s.insert(i + 1);
    vector<int> ans(size, INT_MIN);
    if (x == 2) {
        ans[n - 2] = x + 1;
        ans[n - 1] = x;
        ans[n] = x - 1;
        rep(i, 3) s.erase(i + (x - 1));
        if (n > 2) {
            ans[n + 1] = x + 2;
            s.erase(x + 2);
        }
    }
    else {
        ans[n - 2] = x - 1;
        ans[n - 1] = x;
        ans[n] = x + 1;
        rep(i, 3) s.erase(i + (x - 1));
        if (n > 2) {
            ans[n + 1] = x - 2;
            s.erase(x - 2);
        }
    }
    rep(i, size) {
        if (ans[i] != INT_MIN) continue;
        auto it = s.begin();
        ans[i] = *it;
        s.erase(it);
    }
    cout << "Yes" << endl;
    rep(i, size) cout << ans[i] << endl;
    return 0;
}
