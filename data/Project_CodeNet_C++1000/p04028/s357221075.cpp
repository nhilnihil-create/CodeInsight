#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;

const int maxn = 10010;

const LL mod = 1e9 + 7;

int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}
LL dp1[maxn/2][maxn/2];
int n;
char s[maxn];
int main(){
    memset(dp1, 0, sizeof(dp1));
    dp1[0][0] = 1;
    cin >> n;
    scanf("%s", s + 1);
    int m = strlen(s + 1);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= i;j++){
            if(j > 0){
                dp1[i][j] = (dp1[i][j] + 2LL * dp1[i - 1][j - 1]) % mod;
            }
            dp1[i][j] = (dp1[i][j] + dp1[i - 1][j + 1]) % mod;
        }
        dp1[i][0] = (dp1[i][0] + dp1[i - 1][0]) % mod;
    } 
    LL ans = dp1[n][m];
    LL tmp = qpow(2, m) % mod;
    ans = ans * qpow(tmp, mod - 2) % mod;
    cout << ans << endl;
    return 0;
}
