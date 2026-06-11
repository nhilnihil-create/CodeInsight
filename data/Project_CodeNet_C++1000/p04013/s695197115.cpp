#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <numeric>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll MOD = 1000000007;
const ll INF = 1LL << 60;
#define PI (acos(-1))


ll dp[51][51][2505];
ll a[51];
ll solve()
{

    ll n, x;
    cin >> n >> x;
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    dp[0][0][0] = 1;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            for(int k=0; k < 2501; k++){
                dp[i + 1][j][k] += dp[i][j][k];
                if(k - a[i] >= 0){
                    dp[i + 1][j + 1][k] += dp[i][j][k - a[i]];
                    }
                }
            }
        }
    

    ll ans = 0;
    for(int i=1; i < n + 1; i++){
        for(int j=1; j < 2501; j++){
            if( j % i == 0 && x == j / i){
                ans+=dp[n][i][j];
            }
        }
    }
    cout << ans << endl;

    return 0;
}

int main()
{
    //cout.precision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
