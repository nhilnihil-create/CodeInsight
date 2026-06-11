#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000007;

int main()
{
    int n, k, a[5003];
    cin >> n >> k;
    int least = INF;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= k) least = min(least, a[i]);
    }
    sort(a, a + n, greater<int>());
    int dp[10005];
    fill(dp, dp + 10005, -1);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = k * 2; j >= a[i]; j--){
            if(dp[j - a[i]] != -1){
                if(j - a[i] < k) dp[j] = a[i];
                else dp[j] = dp[j - a[i]];
            }
        }
    }
    for(int i = k; i <= k * 2; i++){
        if(i - k < dp[i]){
            least = min(least, dp[i]);
        }
    }
    if(least == INF) cout << n << endl;
    else{
        reverse(a, a + n);
        cout << lower_bound(a, a + n, least) - a << endl;
    }
}