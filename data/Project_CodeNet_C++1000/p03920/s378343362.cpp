# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <math.h>
# include <algorithm>
using namespace std;
# define lowbit(x) ((x)&(-x))
# define pi acos(-1.0)
# define MAXN 100005
# define eps 1e-5
# define MAXM 500001
# define MOD 1000000007
# define INF 1000000000
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(int i=a; i<=n; ++i)
# define FO(i,a,n) for(int i=a; i<n; ++i)
# define bug puts("H");
typedef long long LL;
typedef unsigned long long ULL;
int _MAX(int a, int b){return a>b?a:b;}
int _MIN(int a, int b){return a>b?b:a;}

int main ()
{
    int n;
    scanf("%d",&n);
    LL l=0, r=n, mid;
    while (l<r) {
        mid=(l+r)>>1;
        if (mid*(mid-1)/2+mid>=n) r=mid;
        else l=mid+1;
    }
    printf("%d\n",r);
    n-=r;
    for (int i=r-1; i>=1&&n; --i) {
        if (n<=i) {printf("%d\n",n); break;}
        else {printf("%d\n",i); n-=i;}
    }
    return 0;
}
