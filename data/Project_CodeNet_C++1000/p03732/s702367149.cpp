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


int main(int argc, char* argv[])
{
    long n,ww;
    scanf("%ld%ld", &n, &ww);

    vector<long> w(n), v(n);
    vector<long> zz[4];
    long i;
    for(i=0; i<n; i++) {
        scanf("%ld%ld", &w[i], &v[i]);
        zz[w[i]-w[0]].push_back(v[i]);
    }
    for(i=0; i<4; i++) {
        sort(zz[i].rbegin(), zz[i].rend());
    }

    vector<long> szz[4];
    long k;
    for(k=0; k<4; k++) {
        szz[k].resize(zz[k].size()+1);
        szz[k][0]=0;
        for(i=0; i<(long)zz[k].size(); i++) {
            szz[k][i+1]=szz[k][i]+zz[k][i];
        }
    }

    long j,m;
    ll ans=0;
    for(i=0; i<=(long)zz[0].size(); i++) {
        ll cst0=i*w[0];
        if(cst0>ww) continue;
        ll sum0=szz[0][i];
        for(j=0; j<=(long)zz[1].size(); j++) {
            ll cst1=cst0+(w[0]+1)*j;
            if(cst1>ww) continue;
            ll sum1 = sum0+szz[1][j];
            for(k=0; k<=(long)zz[2].size(); k++) {
                ll cst2=cst1+(w[0]+2)*k;
                if(cst2>ww) continue;
                ll sum2 = sum1+szz[2][k];
                for(m=0; m<=(long)zz[3].size(); m++) {
                    ll cst3=cst2+(w[0]+3)*m;
                    if(cst3>ww) continue;
                    ll sum3 = sum2+szz[3][m];
                    ans = MAX(ans, sum3);
                }
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
