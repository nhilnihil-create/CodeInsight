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
    vector<int> aa(7);
    int i;
    for(i=0; i<7; i++) {
        scanf("%d", &aa[i]);
    }

    ll ans=0;
    {
        vector<int> a=aa;
        ll cnt=0;
        cnt+=a[1];
        cnt+=(a[3]/2)*2;
        a[3]%=2;
        cnt+=(a[4]/2)*2;
        a[4]%=2;
        if(a[3]==1 && a[4]==1 && a[0]>0) {
            cnt+=3;
            a[3]--; a[4]--; a[0]--;
        }
        cnt+=(a[0]/2)*2;
        ans=MAX(ans,cnt);
    }
    {
        vector<int> a=aa;
        ll cnt=0;
        cnt+=a[1];
        if(a[3]>0 && a[4]>0 && a[0]>0) {
            cnt+=3;
            a[3]--; a[4]--; a[0]--;
        }
        cnt+=(a[3]/2)*2;
        a[3]%=2;
        cnt+=(a[4]/2)*2;
        a[4]%=2;
        cnt+=(a[0]/2)*2;
        ans=MAX(ans,cnt);
    }
    printf("%lld\n", ans);

    return 0;
}

