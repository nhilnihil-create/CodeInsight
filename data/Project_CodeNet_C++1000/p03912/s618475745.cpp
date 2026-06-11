#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100000];
vector<int> B[100000];

int special(int x)
{
    int y=B[x].size();
    return y/2;
}

int paircount(int x)
{
    map<int, int> m;
    for(int i=0; i<(int)B[x].size(); i++)
        m[B[x][i]]++;
    int ret=0;
    for(auto& it: m)
        ret+=it.second/2;
    return ret;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
    {
        scanf("%d", A+i);
        B[A[i]%M].push_back(A[i]);
    }
    int ans=special(0);
    if(M%2==0)
        ans+=special(M/2);
    for(int i=1; i<M-i; i++)
    {
        int x=i;
        int y=M-i;
        sort(B[x].begin(), B[x].end());
        sort(B[y].begin(), B[y].end());
        if(B[x].size()<B[y].size())
            B[x].swap(B[y]);
        int px=paircount(x);
        int py=paircount(y);
        int sx=B[x].size();
        int sy=B[y].size();
        while(sx>sy && px--)
            ans++, sx-=2;
        ans+=min(sx, sy);
    }
    printf("%d\n", ans);
    return 0;
}
