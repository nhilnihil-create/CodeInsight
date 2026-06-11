#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

int n, p;

ll dp[100][2];
int a[100];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> p;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 2;j++){
            int to = (j + a[i]) & 1;
            dp[i][to] += dp[i - 1][j];
            dp[i][j] += dp[i - 1][j];
        }
    }
    cout << dp[n][p] << endl;
    return 0;
}
