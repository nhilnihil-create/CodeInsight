#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
const int maxn = 1e5 + 5;
int dp[maxn][21] , a[maxn] , n , L;
int ask (int x , int c)
{
    int pos = x;
    if (dp[pos][0] == -1) return 1e9;
    for (int i = 20 ; i >= 0 ; i--){
        if (c & (1 << i)){
            if (pos == -1 || dp[pos][i] == -1) return 1e9;
            pos = dp[pos][i];
        }
    }
    if (pos == -1) return 1e9;
    return pos;
}
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
    dp[n][0] = -1;
    for (int i = 1 ; i <= 20 ; i++)
        for (int j = 1 ; j <= n; j++){
            if (dp[j][i - 1] == -1) dp[j][i] = -1;
            else dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
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
        int l = 1 , r = n;
        while (l <= r){
            int mid = l + r >> 1;
            if (ask(x , mid) > y) r = mid - 1;
            else l = mid + 1;
        }
        if (ask(x , r) < y) r++;
        cout << r << endl;
    }
    return 0;
}

/*
9
1 3 6 13 15 18 19 29 31
10
17
1 9
2 9
3 9
4 9
5 9
6 9
7 9
8 9
9 9

9
1 3 6 13 15 18 19 29 31
10
4
4 9
*/
