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
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223372036854775807
#define INF 2147483647
#define MOD 1000000007
using namespace std;

long n,ww;
vector<long> w, v;
vector<long> zz[4];
vector<long> szz[4];

void calc( long k, ll cst0, ll sum0, ll& ans )
{
    if(k==4) {
        ans=MAX(ans,sum0);
        return;
    }
    long j;
    for(j=0; j<=(long)zz[k].size(); j++) {
        ll cst=cst0+j*(w[0]+k);
        if(cst>ww) continue;
        ll sum=sum0+szz[k][j];
        calc(k+1, cst, sum, ans);
    }
    return;
}

int main(int argc, char* argv[])
{
    scanf("%ld%ld", &n, &ww);

    w.resize(n);
    v.resize(n);
    long i;
    for(i=0; i<n; i++) {
        scanf("%ld%ld", &w[i], &v[i]);
        zz[w[i]-w[0]].push_back(v[i]);
    }
    for(i=0; i<4; i++) {
        sort(zz[i].rbegin(), zz[i].rend());
    }

    long k;
    for(k=0; k<4; k++) {
        szz[k].resize(zz[k].size()+1);
        szz[k][0]=0;
        for(i=0; i<(long)zz[k].size(); i++) {
            szz[k][i+1]=szz[k][i]+zz[k][i];
        }
    }

    ll ans=0;
    calc(0,0,0,ans);

    printf("%lld\n", ans);

    return 0;
}
