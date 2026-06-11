#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[307][307];
bool on[307][307];
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            on[i][j] = true;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
   }
   for (int k = 1; k <= n; k++) {
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= n; j++) {
               if (i == j || i == k || j == k) continue;
               if (on[i][j] && on[i][k] && on[k][j] && a[i][j] == a[i][k] + a[k][j]) {
                   on[i][j] = on[j][i] = false;
               }
           }
       }
   }
   ll res = 0;
   for (int i = 1; i <= n; i++) {
       for (int j = i; j <= n; j++) {
           if (on[i][j]) res += a[i][j];
       }
   }
   cout << res << endl;
}

