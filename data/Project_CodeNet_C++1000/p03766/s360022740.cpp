#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
ll N;
const ll inf = 1e9+7;
ll dp[1000010] = {},sum[1000010] = {};

int main(){
    cin >> N;
    dp[1] = N;
    dp[2] = N*N;
    sum[1] = N;
    sum[2] = dp[1]+dp[2];
    for(ll i=3;i<=N;i++){
        dp[i] = (sum[i-1]-dp[i-2]+(N-1)*(N-1)+(N-i+2)+inf)%inf;
        sum[i] = (dp[i]+sum[i-1])%inf;
    }
    cout << (sum[N]-sum[N-1]+inf)%inf << endl;
}