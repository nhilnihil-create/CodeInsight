#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, a[MAXN], c[MAXN], vis[MAXN];
LL k, x[MAXN], y[MAXN], z[MAXN];

vector<int> vec;

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i)
    {
        scanf("%lld", &x[i]);
        y[i]=x[i]-x[i-1];
        c[i]=i;
    }
    scanf("%d%lld", &m, &k);
    for(rint i=1; i<=m; ++i)
    {
        scanf("%d", &a[i]);
        swap(c[a[i]], c[a[i]+1]);
    }
    for(rint i=1; i<=n; ++i)
        if(!vis[i])
        {
            vec.clear();
            vec.push_back(i);
            vis[i]=1;
            for(rint j=c[i]; j!=i; j=c[j])
            {
                vis[j]=1;
                vec.push_back(j);
            }
            for(rint j=0; j<vec.size(); ++j)
                z[vec[j]]=y[vec[(k+j)%vec.size()]];
        }
    for(rint i=1; i<=n; ++i)
    {
        x[i]=x[i-1]+z[i];
        printf("%lld\n", x[i]);
    }
    return 0;
}