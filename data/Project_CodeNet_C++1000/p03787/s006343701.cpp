#include<bits/stdc++.h>
using namespace std;

long long N,M;
vector<int> G[100010];
long long ans = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0;
int res = 0;
int k[100010] = {0};

bool DFS(int v,int c)
{
    k[v] = c;
    bool res = true;
    for(int i = 0; i < G[v].size(); i++)
    {
        int ne = G[v][i];
        if(k[ne] == 0)res &= DFS(ne,-c);
        else if(k[ne] == k[v])res = false;
    }
    return res;
}

int main()
{
    scanf("%lld%lld",&N,&M);
    for(int i = 0; i < M; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
    {
        if(k[i] == 0)
        {
            if(G[i].size() == 0)cnt1++;
            else if(DFS(i,1))cnt2++;
            else cnt3++;
        }
    }

    printf("%lld\n",cnt1 * cnt1 + cnt1 * (N - cnt1) * 2LL + 2LL * cnt2 * cnt2 + 2LL * cnt2 * cnt3 + cnt3 * cnt3);
    return 0;
}
