#include <bits/stdc++.h>
#define N 2000010
#define INF 0x3f3f3f3f

using namespace std;

int n_road,n_rail;
int city;
int road_cont[2][N];
int road[2][N];
bool visit[N];
int cont[N];

set <int> way_con[2][N],temp_cont;
set<int>::iterator it;

int path[N];

int Find(bool way,int x)
{
    //while (x!=road_cont[way][x])x=road_cont[way][x]
    if(x==road_cont[way][x])return x;
    else return road_cont[way][x]=Find(way,road_cont[way][x]);
}

void join(bool way,int a,int b)
{
    if(road[way][a]<road[way][b]) road_cont[way][a]=b;
    else
    {
        road_cont[way][b]=a;
        if(road[way][a]==road[way][b]) ++road[way][a];
    }
}

/*bool ok_road(int a,int b)
{
    if(Find1(a)==Find1(b))return true;
    else return false;
}
bool ok_rail(int a,int b)
{
    if(Find2(a)==Find2(b))return true;
    else return false;
}*/

void Create()
{
    int i;
    int x,y;
    for(i=1; i<=city; ++i)
    {
        road_cont[0][i]=road_cont[1][i]=i;
    }
    for(i=1; i<=n_road; ++i)
    {
        scanf("%d%d",&x,&y);

        int f1=Find(0,x);
        int f2=Find(0,y);
        if(f1!=f2) join(0,f1,f2);
    }
    for(i=1; i<=n_rail; ++i)
    {
        scanf("%d%d",&x,&y);

        int f1=Find(1,x);
        int f2=Find(1,y);
        if(f1!=f2) join(1,f1,f2);
    }
}

int main()
{
    scanf("%d%d%d",&city,&n_road,&n_rail);
    Create();
    for(int i=0; i<=1; ++i)
    {
        for(int j=1; j<=city; ++j)
        {
            way_con[i][Find(i,j)].insert(j);
        }
    }
    int e;
    for(int i=1; i<=city; ++i)
    if(!visit[i])
    {
        e=0;
        int way[2];
        bool ok=0;
        way[0]=Find(0,i);
        way[1]=Find(1,i);
        if(way_con[0][way[0]].size() > way_con[1][way[1]].size())
        {
            ok=1;
        }
        temp_cont=way_con[ok][way[ok]];

        for(it=temp_cont.begin(); it!=temp_cont.end(); ++it)
        {
            int p=*it;
            if(way_con[!ok][way[!ok]].find(p)!=way_con[!ok][way[!ok]].end())
            {
                way_con[ok][way[ok]].erase(p);
                way_con[!ok][way[!ok]].erase(p);
                path[++e]=(p);
                visit[p]=1;
            }
        }
        for(int j=1; j<=e; ++j)
        {
            cont[path[j]]=e;
        }
    }
    for(int i=1; i<=city; ++i)
    {
        if(i!=1)printf(" ");
        printf("%d",cont[i]);
    }
    return 0;
}
