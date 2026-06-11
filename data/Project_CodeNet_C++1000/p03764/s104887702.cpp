#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <string.h>

#define sf scanf
#define pf printf
#define lf double
#define ll long long
#define p123 printf("123\n");
#define pn printf("\n");
#define pk printf(" ");
#define p(n) printf("%d",n);
#define pln(n) printf("%d\n",n);
#define s(n) scanf("%d",&n);
#define ss(n) scanf("%s",n);
#define ps(n) printf("%s",n);
#define sld(n) scanf("%lld",&n);
#define pld(n) printf("%lld",n);
#define slf(n) scanf("%lf",&n);
#define plf(n) printf("%lf",n);
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c",n);
#define gc getchar();
#define re(n,a) memset(n,a,sizeof(n));
#define len(a) strlen(a)
using namespace std;
const ll mod = 1e9+7;
ll a[100050];
ll b[100050];

int main() {
    //pld(C)
    ll n,m;
    sld(n)
    sld(m)
    ll cheng1 = 0;
    ll cheng2 = 0;
    ll sum = 0;
    sld(a[0])
    sum = a[0];
    for(ll i = 1; i < n; i ++){
        sld(a[i])
        cheng1 += (((a[i]*i)%mod)-sum+mod+mod)%mod;
        cheng1 += mod+mod;
        cheng1 %= mod;
        sum += a[i];
        sum %=mod;
    }
    sum = 0;
    sld(b[0])
    sum = b[0];
    for(ll i = 1; i < m; i ++){
        sld(b[i])
        cheng2 += (((b[i]*i)%mod)-sum+mod+mod)%mod;
        cheng2 += mod+mod;
        cheng2 %= mod;
        sum += b[i];
        sum %=mod;
    }
    pld((cheng1*cheng2) %mod) pn



    return 0;
}
