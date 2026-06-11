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
    long n;
    scanf("%ld", &n);

    vector<long> a(n);
    long i;
    for(i=0; i<n; i++) {
        scanf("%ld", &a[i]);
    }

    long p=1;

    ll cnt=0;
    for(i=0; i<n; i++) {
        if(a[i]==p) {
            p++; continue;
        }
        if(p==1) {
            cnt += (a[i]-1);
            p++;
        }
        else if(a[i]%p==0) {
            cnt += (a[i]/p-1);
        }
        else {
            cnt += (a[i]/p);
        }
    }
    printf("%lld\n", cnt);

    return 0;
}
