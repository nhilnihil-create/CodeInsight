#include<bits/stdc++.h>

using namespace std;
#define taskname "A"
#define pb  push_back
#define mp  make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
const int maxn = 4005;

int n, a[maxn] , x;
int dp[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP", "r",stdin);
        freopen(taskname".OUT", "w",stdout);
    }
    cin >> n >> x;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(int i = 0 ; i < n * 2 ; ++i){
        dp[i][i] = a[i];
        for(int j = i + 1 ; j < n * 2 ; ++j){
            dp[i][j] = min(dp[i][j - 1] , a[j]);
        }
    }
    ll ans = 1e18;
    for(int i = 0 ; i < n ; ++i){
        ll res = (ll)x * i;
        for(int j = n ; j < n * 2 ; ++j){
            res += dp[j - i][j];
        }
//        cout << i << " " << res << endl;
        ans = min(ans,res);
    }
    cout << ans;
}
