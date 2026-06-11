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

char str[200005];

void solve()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    vector<int> a(n+1);
    int p,q;
    int good=0;
    for(p=0; p<2; p++) {
        for(q=0; q<2; q++) {
            a[n-1]=p; a[0]=q;
            int i;
            for(i=0; i<n; i++) {
                int tmp=(str[i]=='o'? 0: 1);
                a[(i+1)%n]=(a[(i-1+n)%n]+tmp+a[i])%2;
            }
            if(a[n-1]==p && a[0]==q) {
                good=1;
                break;
            }
        }
        if(good) break;
    }
    if(good) {
        int i;
        for(i=0; i<n; i++) {
            if(a[i]==0) printf("S");
            else printf("W");
        }
        printf("\n");
    }
    else {
        printf("-1\n");
    }

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
