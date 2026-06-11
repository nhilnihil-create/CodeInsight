#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int n, m; cin >> n >> m;
    V<int> sum(n, 1);
    V<bool> red(n, false);

    red[0] = true;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        if(red[x]) red[y] = true;
        sum[x]--;
        sum[y]++;
        if(sum[x] == 0) red[x] = false;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) if(red[i]) ans++;
    cout << ans << endl;

    return 0;
}
