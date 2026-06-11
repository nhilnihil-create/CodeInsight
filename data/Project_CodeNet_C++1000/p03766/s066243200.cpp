#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;
#define MOD 1000000007

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }else if(n==2){
        cout << 4 << endl;
        return 0;
    }
    long long sum = n + n * n;
    long long dp[1000010];
    fill_n(dp, 1000010, 0);
    dp[0] = 0;
    dp[1] = n;
    dp[2] = n*n;

    for(int i=3; i<=n; i++){
        long long tmp = (sum - dp[i-2] + MOD) % MOD;
        dp[i] = ((n-1)*(n-1) % MOD + tmp + (n-i+2)) % MOD;
        sum = (sum + dp[i]) % MOD;
    }
    cout << dp[n] << endl;

    return 0;
}