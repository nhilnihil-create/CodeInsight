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
    int n;
    ll a,b,c,d;
    scanf("%d%lld%lld%lld%lld", &n, &a, &b, &c, &d);

    int i;
    for(i=0; i<=n-1; i++) {
        int j=n-1-i;

        ll min=i*c-j*d;
        ll max=i*d-j*c;
        if(min<=b-a && b-a<=max) {
            printf("YES\n"); return 0;
        }
    }
    printf("NO\n");

    return 0;
}
