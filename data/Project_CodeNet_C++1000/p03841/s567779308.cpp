#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;

struct SHIT
{
    int id;
    int w;
}shit[505];

bool cmp(SHIT a,SHIT b)
{
    return a.w<b.w;
}
bool flag[505*505];
int ans[505*505];
int main()
{
    int n;
    memset(flag,0,sizeof(flag));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&shit[i].w);
        shit[i].id=i;
        flag[shit[i].w]=1;
        ans[shit[i].w]=i;
    }

    sort(shit+1,shit+1+n,cmp);
    int l=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<shit[i].id;j++)
        {
            while(l<=n*n&&flag[l]==1)
                l++;
            if(l>n*n){
                printf("No\n");
                return 0;
            }
            if(l>shit[i].w){
                printf("No\n");
                return 0;
            }
            //printf("%d %d\n",l,shit[i].id);
            ans[l++]=shit[i].id;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=shit[i].id;j<n;j++)
        {
            while(l<=n*n&&flag[l]==1)
                l++;
            if(l>n*n){
                printf("No\n");
                return 0;
            }
            if(l<shit[i].w){
                printf("No\n");
                return 0;
            }
            ans[l++]=shit[i].id;
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n*n;i++)
        printf("%d%c",ans[i],i==n*n?'\n':' ');
    return 0;
}
