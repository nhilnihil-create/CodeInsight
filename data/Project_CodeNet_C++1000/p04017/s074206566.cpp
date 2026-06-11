#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
const int maxn = 1e5 + 5;
int dp[maxn][21] , a[maxn] , n , L;
void solve ()
{
    for (int i = 1 ; i <= n ; i++) {
        int l = 1 , r = n , mid;
        while (l <= r){
            mid = l + r >> 1;
            if (a[mid] <= a[i] + L) l = mid + 1;
            else r = mid - 1;
        }
        dp[i][0] = r;
    }
    for (int i = 1 ; i <= 20 ; i++)
        for (int j = 1 ; j <= n; j++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
}
int ask (int x , int y)
{
    if (x == y) return 0;
    int ans = 0;
    for (int i = 20 ; i >= 0 ; i--)
        if (dp[x][i] < y) x = dp[x][i] , ans += (1 << i);
    ans++;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    cin >> L;
    solve ();
    int q;cin >> q;
    while (q--){
        int x , y; cin >> x >> y;
        if (x > y) swap(x , y);
        cout << ask(x , y) << endl;
    }
    return 0;
}
