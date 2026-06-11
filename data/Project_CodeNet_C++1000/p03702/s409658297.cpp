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


int main(int argc, char* argv[])
{
    int n,a,b;
    scanf("%d%d%d", &n, &a, &b);
    vector<ll> h(n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%lld", &h[i]);
    }

    int c=a-b;
    ll l=0, r=INF;
    while(r-l>1) {
        ll m=(l+r)/2;
        ll cnt=0;
        for(i=0; i<n; i++) {
            ll tmp=h[i]-m*b;
            if(tmp>0) cnt+=(tmp-1+c)/c;
        }
        if(cnt<=m) {
            r=m;
        }
        else {
            l=m;
        }
    }
    printf("%lld\n", r);

    return 0;
}

