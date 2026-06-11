#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;



const int max_comb=200000;
vector<ll> fac(max_comb+1); //n! (mod M)
vector<ll> ifac(max_comb+1); //k!^(-1) (mod M)

ll mpow(ll x, ll n){ //x^n(mod M)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll minv(ll x){
    return mpow( x, MOD-2 );
}

ll comb(int a, int b){     // C(a,b) = a! * b!^(-1) * (a-b)^(-1)
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

ll perm(int a, int b){     // P(a,b) = a! * (a-b)!^(-1)
    if(b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b] % MOD;
    return tmp * fac[a] % MOD;
}

void pre_comb()
{
    fac[0] = 1;
    ifac[0] = 1;
    for(int i = 0; i<max_comb; i++){
        fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod M)
        ifac[i+1] = ifac[i]*minv(i+1) % MOD; // k!^(-1) (mod M)
    }
    return;
}

int main(int argc, char* argv[])
{
    int h,w,a,b;
    scanf("%d%d%d%d", &h, &w, &a, &b);

    pre_comb();

    ll ans=0;
    int i=0;
    for(i=0; i<w-b; i++) {
        ll ans0 = comb(h-1-a+b+i,b+i) * comb(a-1+w-b-1-i, w-b-1-i) %MOD;
        ans = (ans + ans0)%MOD;
    }
    printf("%lld\n", ans);

    return 0;
}
