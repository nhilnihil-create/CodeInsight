#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
    struct newdata
    {
        int label,cnt;
    };
    int n,m;
    int a[301][301];
    newdata rankm[301];
    bool used[301];
bool cmp(newdata i,newdata j)
{
    return (i.cnt>j.cnt);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            if (j==1) rankm[a[i][j]].cnt++;
        }
    int now=0;
    for (int i=1;i<=m;i++)
        rankm[i].label=i;
    int ans=2147483647;
    while (now<m)
    {
        sort(rankm+1,rankm+m+1,cmp);
        ans=min(ans,rankm[1].cnt);
        used[rankm[1].label]=true;
        memset(rankm,0,sizeof(rankm));
        for (int i=1;i<=m;i++)
            rankm[i].label=i;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (!used[a[i][j]])
                {
                    rankm[a[i][j]].cnt++;
                    break;
                }
        now++;
    }
    printf("%d",ans);
}