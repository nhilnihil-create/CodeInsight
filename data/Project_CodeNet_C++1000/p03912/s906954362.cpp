#include <bits/stdc++.h>

#define fr first
#define sc second
#define OK puts("OK");
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long ll;

const int inf = (int)1e9 + 7;
const int N = (int)2e5 + 7;

int n,m;
int a[N],u[N],us[N],db[N],sn[N];
int ans;

 main () {
        cin >> n >> m;

        for (int i = 1; i <= n; i ++) {
                cin >> a[i];
                u[a[i] % m] ++;
                us[a[i]] ++;
        }
        for (int i = 1; i <= n; i ++) {
                if (us[a[i]]) {
                        db[a[i] % m] += (us[a[i]] - (us[a[i]] % 2));
                        sn[a[i] % m] += us[a[i]] % 2;
                        us[a[i]] = 0;
                }
        }
        for (int i = 1; i < (m + 1) / 2; i ++) {
                int f = u[i];
                int s = u[m - i];
                if (f < s) {
                        ans += f;
                        int p = min(0,sn[m - i] - f);
                        db[m - i] += p;
                        ans += (db[m - i] / 2);
                }
                else {
                        ans += s;
                        int p = min(0,sn[i] - s);
                        db[i] += p;
                        ans += (db[i] / 2);
                }
        }
        if (m % 2 == 0) {
                ans += (u[m / 2] / 2);
        }
        ans += (u[0] / 2);

        cout << ans << endl;
}
