#include<bits/stdc++.h>
using namespace std;
#define N 1000000 + 5
#define Mod 1000000007
#define rep(i, l, r) for(int i = l; i <= r; ++i)
int n, ans, sum, dp[N];
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int Inc(int a, int b){ return (a += b) >= Mod ? a - Mod : a;}
int Dec(int a, int b){ return (a -= b) < 0 ? a + Mod : a;}
int Mul(int a, int b){ return 1ll * a * b % Mod;}
int main(){
    n = read();
    dp[0] = sum = 1, ans = Inc(Mul(n - 1, n - 1), 1);
    if(n > 2) ans = Inc(ans, 1);
    rep(i, 1, n - 1){
        dp[i] = sum;
        if(i >= 2) dp[i] = Dec(dp[i], dp[i - 2]); 
        sum = Inc(sum, dp[i]);
        if(i != n - 1) ans = Inc(ans, Mul(dp[i], Inc((Mul(n - 1, n - 1)), min(i + 2, n - 1))));
        else ans = Inc(ans, Mul(dp[i], n));
    }
    printf("%d", ans);
    return 0;
}