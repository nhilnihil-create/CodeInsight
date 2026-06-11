#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool all_same(string s) {
    bool ret = true;
    rep(i,s.size()-1) {
        if (s[i] != s[i+1]) {
            ret = false;
            break;
        }
    }
    return ret;
}

int main() {
    string start;
    cin >> start;
    int ans = 1001001001;
    rep(i,26) {
        char target = 'a' + i;
        string s = start;
        int cnt = 0;
        while (!all_same(s)) {
            cnt++;
            string t;
            rep(i,s.size()-1) {
                if (s[i+1] == target) t.push_back(s[i+1]);
                else t.push_back(s[i]);
            }
            s = t;
        }
        ans = min(cnt, ans);
    }
    cout << ans << endl;
}