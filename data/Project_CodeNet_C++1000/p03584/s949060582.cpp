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
#include <list>
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
#define MOD 1000000007
using namespace std;


int main(int argc, char* argv[])
{
    long n, k;
    scanf("%ld%ld", &n, &k);
    k++;

    vector<long> a(n);
    vector<pair<long, long> > z(n);   // a[i],b[i]
    long i;
    for(i=0; i<n; i++) {
        long b;
        scanf("%ld%ld", &a[i], &b);
        z[i] = make_pair(a[i], b);
    }
    sort(a.begin(), a.end());
    sort(z.begin(), z.end());

    ll ans=0;
    for(i=30; i>=0; i--) {
        if(k & (1<<i)) {
            ll add = (1<<i);
            long i1 = lower_bound(a.begin(), a.end(), add) - a.begin();
            ll val = 0;
            long p;
            for(p=0; p<i1; p++) {
                val += z[p].second;
            }
            ans = MAX(ans, val);

            for(p=0; p<n; p++) {
                z[p].first &= ~(1<<i);
            }
            sort(z.begin(), z.end());
            for(p=0; p<n; p++) {
                a[p] = z[p].first;
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
