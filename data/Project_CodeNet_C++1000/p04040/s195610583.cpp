#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
const ull MOD = 1e9+7;

int H,W,A,B;
ll cnt;
ll fact[2*100010];
ll frev[2*100010];

ll rev(ll a, ll p){
    if(p == 0) return 1;
    ll tmp = rev(a, p/2);
    tmp = tmp * tmp % MOD;
    if(p % 2 == 1) tmp = tmp * a % MOD;
    return tmp;
}

ll comb(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 || k == 0) return 1;
    return fact[n] * frev[k] % MOD * frev[n-k] % MOD;
}

ll square(int x0, int y0, int x1, int y1){
    int xx = x1 - x0;
    int yy = y1 - y0;
    return comb(xx+yy, min(xx,yy)) % MOD;
}

int main(){
    cin >> H >> W >> A >> B;

    fact[0] = frev[0] = 1;
    for(int i = 1; i <= 200000; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        frev[i] = rev(fact[i], MOD-2);
    }

    for(int w = B; w < W; w++){
        cnt += square(0,0,w,H-A-1) * square(w,H-A,W-1,H-1) % MOD;
    }
    //cnt = square(0,0,4,4);
    //cnt = comb(8,4);
    cout << cnt % MOD << endl;
    return 0;
}
