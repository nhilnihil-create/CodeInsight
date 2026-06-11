#include <bits/stdc++.h>
using namespace std;

#define int long long

int A[52];
long long DP[52][52][2502];

void solve() {
    int n, a;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        cin >> A[i+1];
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= 2500; k++) {
            DP[i][1][k] = DP[i - 1][1][k];
        }
        DP[i][1][A[i]]++;
    }

    for (int j = 2; j <= n; j++)
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 2500; k++) {
                DP[i][j][k] += DP[i - 1][j][k];
                DP[i][j][k] += DP[i - 1][j-1][max(k - A[i], 0LL)];
                //if(DP[i][j][k] > 0)
                //cout << DP[i][j][k] << "\n";
            }
        }
//    for(int i = 0; i <= n; i++){
//
//        for(int k = 0; k <= 33; k++)
//            cout << DP[1][i][k] << " ";
//        cout << "\n";
//    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += DP[n][i][a * i];
    cout << ans << "\n";
}

#undef int

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool multitest = false;
    // multitest = true;
    if (multitest) {
        int t; cin >> t;
        while (t--)
            solve();
    }
    else
        solve();
}


