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
const int N = 1e6;
const int K = 15;

int n, k, x, temp;
int dis[K];
bool valid;

void solve() {
    int T = 1;
  #ifdef multicase
    cin >> T;
  #endif
    for(int tc = 1; tc <= T; tc++) {
        cin >> n >> k;
        while(k--) {
            cin >> x;
            dis[x] = true;
        }
        for(int i = n; i <= N; i++) {
            temp = i;
            valid = true;
            while(temp) {
                if(dis[temp % 10]) valid = false;
                temp /= 10;
            }
            if(valid) {
                cout << i << "\n";
                return;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
}