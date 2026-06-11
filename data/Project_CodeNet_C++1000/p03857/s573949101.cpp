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
int connected[N];

set <int> way_cont[2][N],temp_cont;
set <int>::iterator it;

int Find(bool way,int x)
{
    if(x==road_cont[way][x])return x;
    else
    {
        road_cont[way][x]=Find(way,road_cont[way][x]);
        return road_cont[way][x];
    }
}

void join(bool way,int a,int b)
{
    if(road[way][a]<road[way][b])
    {
        road_cont[way][a]=b;
        ++road[way][a];
    }
    else
    {
        road_cont[way][b]=a;
        ++road[way][b];
    }
}

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
    //Create_tree
    for(int j=1; j<=city; ++j)
    {
        way_cont[0][Find(0,j)].insert(j);
        way_cont[1][Find(1,j)].insert(j);
    }

    memset(visit,0,sizeof(visit));
}

void Travel_Tree()
{
    for(int i=1; i<=city; i++)
    {
        if(visit[i])continue;
        int top=0;
        int Root1,Root2;
        Root1=Find(0,i);
        Root2=Find(1,i);

        bool road;
        if(way_cont[0][Root1].size() > way_cont[1][Root2].size())
        {
            temp_cont=way_cont[1][Root2];
            road=true;
        }
        else
        {
            temp_cont=way_cont[0][Root1];
            road=false;
            int t=Root1;
            Root1=Root2;
            Root2=t;
        }

        for(it=temp_cont.begin(); it!=temp_cont.end(); it++)
        {
            int p=*it;
            if(way_cont[!road][Root1].find(p)!=way_cont[!road][Root1].end())
            {
                top++;
                connected[top]=(p);
                visit[p]=1;
                /*cont[p]++;

                */

                way_cont[road][Root2].erase(p);
                way_cont[!road][Root1].erase(p);
            }
        }
        for(int j=1; j<=top; j++)
        {
            cont[connected[j]]=top;
        }
    }
}

int main()
{
    scanf("%d%d%d",&city,&n_road,&n_rail);
    Create();
    Travel_Tree();
    for(int i=1; i<=city; ++i)
    {
        if(i!=1)printf(" ");
        printf("%d",cont[i]);
    }
    printf("\n");
    return 0;
}
