#include <cstdio>
#include <algorithm>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

int n,p[510],a[510],cnt[510],ans[250100];

bool cmp(int x,int y)
{
    return p[x]<p[y];
}

bool solve()
{
    for (int i=1,j=1,k=1; i<=n*n; ++i)
        if (!ans[i])
        {
            for (; j<=n && cnt[a[j]]+1>=a[j]; ++j);
            for (; cnt[a[k]]==n; ++k);
            if (j<=n)
                ++cnt[ans[i]=a[j]];
            else
            {
                if (k==j)
                    return 0;
                ++cnt[ans[i]=a[k]];
            }
        }
        else
            if (++cnt[ans[i]]!=ans[i])
                return 0;
    return 1;
}

int main()
{
    scanf("%d",&n);
    repu(i,1,n)
        scanf("%d",&p[i]),ans[p[i]]=a[i]=i;
    sort(a+1,a+1+n,cmp);
    if (solve())
    {
        puts("Yes");
        repu(i,1,n*n)
            printf("%d ",ans[i]);
    }
    else
        puts("No");
    return 0;
}