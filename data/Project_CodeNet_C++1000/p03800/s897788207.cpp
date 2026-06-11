#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

ll N;
string s;

bool solve(string ans) {
    for (ll i = 1; i <= N; i++) {
        string pre = ans.substr(i-1, 2);
        if (s[i] == 'o') {
            if (pre == "SS" || pre == "WW") ans += 'S';
            else ans += 'W';
        } else {
            if (pre == "WS" || pre == "SW") ans += 'S';
            else ans += 'W';
        }
    }

    if (ans[N] == ans[0] && ans[N+1] == ans[1]) {
        cout << ans.substr(0, N) << "\n";
        return true;
    } else return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> s;
    s += s[0];

    if (solve("SS")) return 0;
    if (solve("SW")) return 0;
    if (solve("WS")) return 0;
    if (solve("WW")) return 0;

    cout << -1 << "\n";
}