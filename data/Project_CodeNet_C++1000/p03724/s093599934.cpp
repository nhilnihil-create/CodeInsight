#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20)
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

int n, m, a;
int cnt[111111] = {};

signed main() {
    INCANT;
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        cin>>a;
        cnt[a]++;
        cin>>a;
        cnt[a]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] % 2) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}