#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
vector<int>rec[maxn];
int ans[maxn];
int len[maxn];
int shendu[maxn];
typedef struct
{
    int id,d,color;
}qq;
qq a[maxn];
queue<int>po;
void bfs(int name,int col,int distance)
{
    shendu[name]=0;
    if(len[name]<distance)
    {
        po.push(name);
        if(ans[name]==0)
        {
            ans[name]=col;
        }
        len[name]=distance;
    }
    while(!po.empty())
    {
        int temp=po.front();
        po.pop();
        for(int i=0; i<rec[temp].size(); i++)
        {
            int zhi=rec[temp][i];

            if(len[zhi]<distance-shendu[temp]-1)
            {
                shendu[zhi]=shendu[temp]+1;
                po.push(zhi);
                len[zhi]=distance-shendu[zhi];
                if(ans[zhi]==0)
                {
                    ans[zhi]=col;
                }
            }
        }

    }
}
int n,m;
void init()
{
    for(int i=0;i<=n;i++)
    {
        len[i]=-1;
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n>>m;
    init();
    int le,ri;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&le,&ri);
        rec[le].push_back(ri);
        rec[ri].push_back(le);
    }
    int q;
    cin>>q;
//    for(int i=0;i<rec[6].size();i++)
//    {
//        printf("*%d\n",rec[6][i]);
//    }
    for(int i=0; i<q; i++)
    {
        scanf("%d%d%d",&a[i].id,&a[i].d,&a[i].color);
    }
    for(int i=q-1; i>=0; i--)
    {
        bfs(a[i].id,a[i].color,a[i].d);
    }
    for(int i=1; i<=n; i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
