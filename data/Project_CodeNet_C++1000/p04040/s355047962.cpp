/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007;

LL fact[200000];
LL inv_fact[200000];

LL modpow(int a, int b){
    if (b == 0){
        return 1;
    }
    else if (b & 1){
        return (a * modpow(a, b - 1)) % MOD;
    }
    else{
        LL d = modpow(a, b / 2);
        return (d * d) % MOD;
    }
}

LL fermat_little(int n){
    int a = modpow(n, MOD - 2);
    return a;
}

void gen(int n){
    fact[0] = 1;
    inv_fact[0] = -1;
    for (LL i = 1; i <= n; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
        inv_fact[i] = fermat_little(fact[i]);
    }
}

LL choose(int n, int k){
    if (n < k) return 0;
    if (k == 0) return 1;
    if (n == k) return 1;
    LL ans = fact[n];
    ans *= inv_fact[k]; ans %= MOD;
    ans *= inv_fact[n-k]; ans %= MOD;
    return ans;
}


int main()
{
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    gen(h + w - 1);
    LL ans = 0;
    for (int i = b + 1; i <= w; i++){
        ans += (choose(h-a+i-2, h-a-1) * choose(w-i+a-1,w-i)) % MOD;
        ans %= MOD;
    }
    cout << ans<< endl;
    return 0;
}








