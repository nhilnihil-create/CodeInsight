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
    int n,k;
    scanf("%d%d", &n, &k);

    vector<int> a(n);
    vector<ll> sa(n+1),s0(n+1);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
        sa[i+1]=sa[i]+a[i];
        s0[i+1]=s0[i]+(a[i]>0? a[i]: 0);
    }

    ll max=-LINF;
    for(i=0; i<=n-k; i++) {
        ll tmp0=s0[n]-(s0[i+k]-s0[i]);
        max=MAX(max,tmp0);
        ll tmp1=s0[n]-(s0[i+k]-s0[i])+(sa[i+k]-sa[i]);
        max=MAX(max,tmp1);
    }
    printf("%lld\n", max);

    return 0;
}

