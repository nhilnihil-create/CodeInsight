#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int lenS, n;
char s[5005];

long long pangkat(long long base, long long pang){
    long long ret = 1;
    while(pang){
        if (pang & 1){
            ret = (ret * base) % MOD;
        }
        base = (base*base) % MOD;
        pang >>= 1;
    }
    return ret;
}

long long memo[5005][5005];

long long f(int fixed, int index){
    if (fixed == lenS && index == n)
        return 1;

    if (index == n && fixed != lenS) return 0;

    long long &ret = memo[fixed][index];
    if (ret != -1) return ret;

    if (fixed == 0){
        ret = 2*f(fixed+1, index+1) + f(fixed, index+1);
    }
    else{
        ret = f(fixed-1, index+1) + 2*f(fixed+1, index+1);
    }
    ret %= MOD;
    return ret;
}
int main(){
    scanf("%d", &n);
    scanf("%s", s);
    lenS = strlen(s);
    memset(memo, -1, sizeof(memo));

    printf("%lld\n", (f(0,0)*pangkat(pangkat(2, lenS) % MOD, MOD-2)) % MOD);
}