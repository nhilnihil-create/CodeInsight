#include <bits/stdc++.h>

using namespace std;

int n,m,root[100010],lc[20000010],rc[20000010],now,sum[20000010];
vector <int> V[100010];

void pushup(int o)
{
    sum[o] = sum[lc[o]] + sum[rc[o]];
}

void insert(int o1,int &o2,int l,int r,int pos)
{
    if (!o2 || o1 == o2)
        o2 = ++now;
    lc[o2] = lc[o1];
    rc[o2] = rc[o1];
    sum[o2] = sum[o1];
    if (l == r)
    {
        sum[o2]++;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        insert(lc[o1],lc[o2],l,mid,pos);
    else
        insert(rc[o1],rc[o2],mid + 1,r,pos);
    pushup(o2);
}

int query(int o,int l,int r,int x,int y)
{
    if (!o)
        return 0;
    if (x > y)
        return 0;
    if (x <= l && r <= y)
        return sum[o];
    int mid = (l + r) >> 1,res = 0;
    if (x <= mid)
        res += query(lc[o],l,mid,x,y);
    if (y > mid)
        res += query(rc[o],mid + 1,r,x,y);
    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        V[y].push_back(x);
    }
    for (int i = 1; i <= m; i++)
    {
        root[i] = root[i - 1];
        for (int j = 0; j < V[i].size(); j++)
            insert(root[i],root[i],1,m,V[i][j]);
    }
    for (int i = 1; i <= m; i++)
    {
        int temp = 0,ans = 0;
        for (int j = i; j <= m; j += i)
        {
            ans += query(root[j - 1],1,m,temp + 1,j - 1);
            temp = j;
        }
        ans += query(root[m],1,m,temp + 1,m);
        printf("%d\n",n - ans);
    }

    return 0;
}
