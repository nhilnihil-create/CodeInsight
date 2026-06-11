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
    long w, h;
    scanf("%ld%ld", &w, &h);

    vector<ll> ww(w), hh(h);
    vector<pair<ll, pair<long,long> > >  z;    // cost, type(0/1), id   
    long i;
    for(i=0; i<w; i++) {
        scanf("%lld", &ww[i]);
        z.push_back(make_pair( ww[i], make_pair(i, 0) ));
    }
    for(i=0; i<h; i++) {
        scanf("%lld", &hh[i]);
        z.push_back(make_pair( hh[i], make_pair(i, 1) ));
    }
    sort(z.begin(), z.end());

    ll ans=0;

    long numw=w+1;
    long numh=h+1;

    for(i=0; i<w+h; i++) {
        long id = z[i].second.first;
        long type = z[i].second.second;
        if(type==0) {
            ans += (ll)numh*z[i].first;
            numw--;
        }
        else {
            ans += (ll)numw*z[i].first;
            numh--;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
