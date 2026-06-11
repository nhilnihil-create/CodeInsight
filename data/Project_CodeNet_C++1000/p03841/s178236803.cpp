#include<bits/stdc++.h>
using namespace std;

#define se second
#define fi first
#define mk(a,b) make_pair(a,b)

int N,X[300010];
int ans[300010] = {0};
vector<pair<int,int> > V;

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)scanf("%d",X + i);
    for(int i = 0; i < N; i++)ans[X[i] - 1] = 1 + i;
    for(int i = 0; i < N; i++)V.push_back(mk(X[i],i));
    sort(V.begin(),V.end());
    vector<int> mem,mem2;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < V[i].se; j++)mem.push_back(V[i].se + 1);
        for(int j = 0; j < N - V[i].se - 1; j++)mem2.push_back(V[i].se + 1);
    }
    reverse(mem2.begin(),mem2.end());

    int cnt = 0;
    for(int i = 0; i < N * N; i++)
    {
        if(cnt != mem.size() && ans[i] == 0)
        {
            ans[i] = mem[cnt];
            cnt++;
        }
    }
    cnt = 0;
    for(int i = N * N - 1; i >= 0; i--)
    {
        if(cnt != mem2.size() && ans[i] == 0)
        {
            ans[i] = mem2[cnt];
            cnt++;
        }
    }
    for(int i = 1; i <= N; i++)
    {
        cnt = 0;
        for(int j = 0; j < N * N; j++)
        {
            if(X[i - 1] == j + 1)
            {
                if(cnt != i - 1)
                {
                    printf("No\n");
                    return 0;
                }
            }
            if(ans[j] == i)cnt++;
        }
    }
    printf("Yes\n");
    for(int i = 0; i < N * N; i++)
    {
        printf("%d",ans[i]);
        if(i != N * N - 1)printf(" ");
    }
    printf("\n");
    return 0;
}
