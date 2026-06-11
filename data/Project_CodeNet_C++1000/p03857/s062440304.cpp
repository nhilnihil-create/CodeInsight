#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxv = 200010;
const int maxe = 100010;
int vertex, RailEdge, RoadEdge, cnt;
int RailHead[maxv], RoadHead[maxv], number[maxv], ans[maxv];
bool vis[maxv];
vector <int> v[maxv];
struct Edge
{
    int to, next;
}e[maxe * 4];

void addEdge(int *head, int from, int to)
{
    e[cnt].next = head[from];
    e[cnt].to = to;
    head[from] = cnt++;
}

void getNumberDFS(int cur)
{
    vis[cur] = true;
    number[cur] = cnt;
    for (int i = RoadHead[cur]; ~i; i = e[i].next)
    {
        int to = e[i].to;
        if (!vis[to])
            getNumberDFS(to);
    }
}

vector <int> valid;

void DFS(int cur)
{
    vis[cur] = true;
    int curNumber = number[cur];
    if (v[curNumber].size() == 0)
        valid.push_back(curNumber);
    v[curNumber].push_back(cur);
    for (int i = RailHead[cur]; ~i; i = e[i].next)
    {
        if (!vis[e[i].to])
            DFS(e[i].to);
    }
}

int main()
{
    memset(RailHead, -1, sizeof(RailHead));
    memset(RoadHead, -1, sizeof(RoadHead));
    for (int i = 0; i < maxv; i++)
        ans[i] = 1;


    int from, to;
    scanf("%d %d %d", &vertex, &RoadEdge, &RailEdge);
    for (int i = 0; i < RoadEdge; i++)
    {
        scanf("%d %d", &from, &to);
        addEdge(RoadHead, from, to);
        addEdge(RoadHead, to, from);
    }
    for (int i = 0; i < RailEdge; i++)
    {
        scanf("%d %d", &from, &to);
        addEdge(RailHead, from, to);
        addEdge(RailHead, to, from);
    }
    cnt = 0;
    for (int i = 1; i <= vertex; i++)
    {
        if (!vis[i])
        {
            getNumberDFS(i);
            cnt++;
        }
    }
//    printf("number:\n");
//    for (int i = 1; i <= vertex; i++)
//        printf("%d%c", number[i], i == vertex ? '\n' : ' ');
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= vertex; i++)
    {
        if (!vis[i])
        {
            DFS(i);
            for (int i = 0; i < valid.size(); i++)
            {
                int id = valid[i];
                for (int j = 0; j < v[id].size(); j++)
                    ans[v[id][j]] += v[id].size() - 1;
                v[id].clear();
            }
            valid.clear();
        }
    }
//    printf("answer:\n");
    for (int i = 1; i <= vertex; i++)
        printf("%d%c", ans[i], i == vertex ? '\n' : ' ');
    return 0;
}
/*
7 5 5
1 2
2 3
2 5
6 7
5 6
3 5
4 5
3 4
6 7
5 6
 
 1 1 4 1 4 4 4
 */


