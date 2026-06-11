#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<bitset>
#define Fail puts("NO"),exit(0);
#define eps 1e-10
#define maxn 505
#define maxm 4010
#define inf 1000000007
#define mod 998244353
#define inv 499122177
#define G 3
#define pi acos(-1)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef bitset<maxn> bit;
typedef long double ld;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
pii a[maxn];
int ans[maxn*maxn];
int main() 
{
    n=read();
    for(int i=1;i<=n;i++)  a[i]=mp(read(),i);
    sort(a+1,a+n+1);
    int now=1;
    for(int i=1;i<=n;i++)
    {
        if(ans[a[i].fi])
        {
            puts("No");
            return 0;
        }
        ans[a[i].fi]=a[i].se;
        for(int j=1;j<a[i].se;j++)
        {
            while(ans[now])  now++;
            if(now>a[i].fi)
            {
                puts("No");
                return 0;
            }
            ans[now]=a[i].se;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-a[i].se;j++)
        {
            while(ans[now])  now++;
            if(now<a[i].fi)
            {
                puts("No");
                return 0;
            }
            ans[now]=a[i].se;
        }
    }
    puts("Yes");
    for(int i=1;i<=n*n;i++)  printf("%d ",ans[i]);
    puts("");
    return 0;
}