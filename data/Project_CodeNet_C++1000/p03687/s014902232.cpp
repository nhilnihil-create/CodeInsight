#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

string s;
int ans;

bool SameAll(string x) {
    for(int i = 1; i < x.size(); i++) {
        if(x[i] != x[i - 1]) return false;
    }
    return true;
}

int f(string x, char c) {
    x = c + x + c;
    int pos = 0, res = 0;
    for(int i = 1; i < x.size(); i++) {
        if(x[i] == c) {
            res = max(res, i - pos - 1);
            pos = i;
        }
    }
    return res;
}

void solve() {
    cin >> s;
    if(SameAll(s)) cout << "0\n";
    else {
        ans = INF;
        for(int i = 0; i < s.size(); i++) {
            ans = min(ans, f(s, s[i]));
        }
        cout << ans << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}