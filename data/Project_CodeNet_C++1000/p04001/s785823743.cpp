#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
const int maxn = 4e5 + 5;
ll dp[maxn];
string a;
ll solve (int l , int r)
{
    ll now = 0;
    for (int i = l ; i <= r ; i++){
        now = now * 10 + (a[i] - '0');
    }
    return now;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> a;
    int n = a.size();
    a = '#' + a;
    for (int i = 1 ; i <= n ; i++){
        dp[i] = solve(1 , i);
        if (i != 1) dp[i] += dp[1] + solve(2 , i);
        for (int j = 3 ; j <= i ; j++){
            dp[i] += dp[j - 1] + (1ll << (j - 2)) * solve(j , i);
        }
     //   cout << i << " " << dp[i] << endl;
    }
    cout << dp[n] << endl;
    return 0;
}


/*
6 7
1 2 1
2 4 1
1 3 3
3 4 3
4 6 2
4 5 3
5 6 3
4 3
1 2 1
2 3 1
3 4 2
*/

