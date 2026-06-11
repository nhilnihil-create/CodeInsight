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
const int N = 1e2 + 5;

int n, l;
string s[N];

void solve() {
    int T = 1;
  #ifdef multicase
    cin >> T;
  #endif
    for(int tc = 1; tc <= T; tc++) {
        cin >> n >> l;
        for(int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        sort(s + 1, s + n + 1);
        for(int i = 1; i <= n; i++) cout << s[i];
        cout << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
}