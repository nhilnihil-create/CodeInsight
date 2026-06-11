#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define vt vector
#define pq priority_queue
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)
// #define multicase
const int MOD = 1e9 + 7;
const int INF = 2e9;
// const int N = ;

string s, ans;

void solve() {
    int T = 1;
  #ifdef multicase
    cin >> T;
  #endif
    for(int tc = 1; tc <= T; tc++) {
        cin >> s;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') ans += '1';
            else if(s[i] == '0') ans += '0';
            else {
                if(ans.size())
                    ans.erase(ans.size() - 1);
            }
        }
        cout << ans << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
}