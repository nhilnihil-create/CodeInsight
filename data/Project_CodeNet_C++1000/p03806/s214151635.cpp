#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    int a, b, c;
    vector<vector<int>> arr;
    int sA = 0, sB = 0, sC = 0;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        arr.push_back({a, b, c});
        sA += a;
        sB += b;
        sC += c;
    }
    vector<vector<int>> dp(sA+1, vector<int>(sB+1, sC+1));
    dp[0][0] = 0;
    for(int k = 0; k < n; k++) {
        a = arr[k][0];
        b = arr[k][1];
        c = arr[k][2];
        for(int i = sA; i >= a; i--) {
            for(int j = sB; j >= b; j--) {
                dp[i][j] = min(dp[i][j], dp[i-a][j-b] + c);
            }
        }
    }
    int ans = sC+1;
    for(int k = 1;; k++) {
        if (ma*k > sA || mb*k > sB)
            break;
        ans = min(ans, dp[ma*k][mb*k]);
    }
    if (ans == sC+1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}


