#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int cnt[N], sum[N];
int n, m, x, mx;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x % m]++;
        sum[x]++;
        mx = max(mx, x);
    }
    /*for(int i=0;i<m;i++) {
        cout << i << "->" << cnt[i] << endl;
    }*/
    long long ans = cnt[0]/2;
    cnt[0] = 0;
    for (int i = 1; i < m; i++) {
        if (!cnt[i]) continue;
        if(i == m-i) {
            //cout << "add " << cnt[i]/2 << " at " << i << endl;
            ans += cnt[i]/2;
            cnt[i] %= 2;
        } else {
            int res = min(cnt[i], cnt[m-i]);
            //cout << "add " << res << " at " << i << endl;
            ans += res;
            cnt[i] -= res, cnt[m-i] -= res;
        }
    }
    for(int i=0;i<=mx;i++) {
        int pair = min(sum[i], cnt[i%m]);
        //cout << "pair " << pair << " at " << i << endl;
        //cout << sum[i] << "," << cnt[i%m] << endl;
        if(pair < 2) continue;
        cnt[i%m] -= pair/2*2;
        sum[i] -= pair/2*2;
        ans += pair/2;
    }
    cout << ans << endl;
    return 0;
}