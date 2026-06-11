#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x,y;
    long long w;
};
vector<node>edge;
long long a[305][305],b[305][305],sum;
bool vis[305][305];
int n,prnt[305];

bool comp(node na,node nb)
{
    return  (na.w<nb.w);
}

void FW1()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                b[i][j] = min(b[i][j],(b[i][k]+b[k][j]));
            }
        }
    }
    return;
}

void FW2()
{
    sum = 0;
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                long long x = a[i][j];
                long long y = a[i][k]+a[k][j];
                if(k!=i && k!=j && y==x)
                {
                    //cout<<i<<" "<<j<<endl;
                    vis[i][j] = vis[j][i] = true;
                }
                /*if(x!=y)    vis[i][j] = true;
                if(y==b[i][j])
                {
                    if(!vis[i][k])
                    {
                        sum += a[i][k];
                        vis[i][k] = vis[k][i] = true;
                    }
                    if(!vis[k][j])
                    {
                        sum += a[k][j];
                        vis[k][j] = vis[j][k] = true;
                    }
                }
                else if(x==b[i][j])
                {
                    if(!vis[i][j])
                    {
                        sum += a[i][j];
                        vis[i][j] = vis[j][i] = true;
                    }
                }*/
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(!vis[i][j])  sum += a[i][j];
        }
    }
    sum /= 2;
    return;
}

/*
int find_p(int x)
{
    if(prnt[x]==x)  return  x;
    else    return  prnt[x] = find_p(prnt[x]);
}

void MST()
{
    int x,y,c=0;
    sort(edge.begin(),edge.end(),comp);
    for(int i=1; i<=n; i++) prnt[i] = i;
    for(int i=0; i<edge.size(); i++)
    {
        x = find_p(edge[i].x);
        y = find_p(edge[i].y);
        if(x!=y)
        {
            prnt[y] = x;
            sum += edge[i].w;
            c++;
            vis[x][y] = true;
        }
        if(c==n-1)  break;
    }
}

void ADD()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(vis[i][j])   continue;
            if(a[i][j]<=b[i][j]) sum += a[i][j];
        }
    }
    return;
}
*/
long long check()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(b[i][j]!=a[i][j])    return  -1;
            edge.push_back(node({i,j,b[i][j]}));
            //sum += b[i][j];
        }
    }
    FW2();
    //MST();
    //ADD();
    return  sum;
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%lld",&a[i][j]);
            b[i][j] = a[i][j];
        }
    }
    FW1();
    printf("%lld\n",check());
    return  0;
}
