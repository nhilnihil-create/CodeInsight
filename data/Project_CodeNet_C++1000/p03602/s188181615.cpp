#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define pii pair<int,int>
#define pi acos(-1)
#define pb push_back
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

ll a[310][310];
bool vis[310][310];

int main()
{
#ifdef local
    freopen("data.txt","r",stdin);
#endif
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%lld",&a[i][j]);
    int flag=1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            if(i==j) continue;
            for(int k=1; k<=n; k++) {
                if(i==k||j==k) continue;
                if(a[i][k]+a[k][j]<a[i][j]) flag=0;
                if(a[i][k]+a[k][j]==a[i][j]) vis[i][j]=1;
            }
        }
    if(!flag) {
        puts("-1");
        return 0;
    }
    ll ans=0;
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(!vis[i][j]) ans+=a[i][j];
    printf("%lld\n",ans);
    return 0;
}
