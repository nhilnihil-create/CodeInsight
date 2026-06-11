#include <iostream>
#include <vector>
using namespace std;
long long const mod = 1e9+7;

long long mod_pow(long long a, long long b){
    long long res = 1;
    a %= mod;
    while(b > 0){
        if(b%2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int main(void){
    int n, len;
    string s;
    vector< vector<long long> > dp;
    cin >> n >> s;
    len = s.length();
    dp.assign(2, vector<long long>());
    for(int i=0;i<2;i++){
        dp[i].assign(n+2, 0);
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        int a = i%2, b = (i+1)%2;
        dp[a][0] = dp[b][0] + dp[b][1];
        for(int j=1;j<=i;j++){
            dp[a][j] = dp[b][j-1] * 2 + dp[b][j+1];
            dp[a][j] %= mod;
        }
    }
    cout << (dp[n%2][len] * mod_pow(mod_pow(2, len), mod-2)) % mod << endl;

}
