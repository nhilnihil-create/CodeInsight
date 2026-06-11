#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

const int MAXN = 2e3 + 21;

long long n, x;
long long ans;
long long a[MAXN], mn[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mn[0][i] = a[i];
        ans += a[i];
    }

    for(int i = 1; i < n; i++) {
        long long sum = 0;
        for(int j = 0; j < n; j++) {
            int chk = j - i;
            if(chk < 0)
                chk = n + chk;
            mn[i][j] = min(mn[i - 1][j], a[chk]);
            sum += mn[i][j];
        }
        ans = min(ans, sum + i * x);
    }

    cout << ans << '\n';
    return 0;
}

