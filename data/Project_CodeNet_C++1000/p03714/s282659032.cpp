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
    long n;
    scanf("%ld", &n);
    vector<long> a(3*n);
    long i;
    for(i=0; i<3*n; i++) {
        scanf("%ld", &a[i]);
    }

    vector<ll> s0(n+1);
    {
        ll sum0=0;
        set<pair<long,long> > zz;
        for(i=0; i<n; i++) {
            zz.insert( make_pair( a[i], i) );
            sum0+=a[i];
        }
        s0[0]=sum0;
        for(i=n; i<n*2; i++) {
            zz.insert( make_pair( a[i], i) );
            sum0+=a[i];

            auto it=zz.begin();
            sum0-=(it->first);
            zz.erase( it );
            s0[i+1-n]=sum0;
        }
    }

    vector<ll> s1(n+1);
    {
        reverse(a.begin(), a.end());
        ll sum0=0;
        set<pair<long,long> > zz;
        for(i=0; i<n; i++) {
            zz.insert( make_pair( a[i], i) );
            sum0+=a[i];
        }
        s1[0]=sum0;
        for(i=n; i<n*2; i++) {
            zz.insert( make_pair( a[i], i) );
            sum0+=a[i];

            auto it=zz.end();
            it--;
            sum0-=(it->first);
            zz.erase( it );
            s1[i+1-n]=sum0;
        }
    }

    ll max=-LINF;
    for(i=0; i<=n; i++) {
        ll val = (s0[i] - s1[n-i]);
        max = MAX(max, val);
    }

    printf("%lld\n", max);

    return 0;
}

