#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int N = 1e5 + 7;

int cnt[N];
int red[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        if ( i == 1) {
            red[i] = 1;
            cnt[i] = 1;
        } else {
            cnt[i] = 1;
        }
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (red[x]) {
            red[y] = 1;
            cnt[x]--;
            cnt[y]++;
            if (!cnt[x]) {
                red[x] = 0;
            }
        } else {
            cnt[x]--;
            cnt[y]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <=  n; i++) ans += red[i];
    cout << ans << '\n';
    return 0;
}
