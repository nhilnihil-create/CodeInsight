#include<bits/stdc++.h>
using namespace std;
const int MAXN = 131072;
int idx[2*MAXN];
int getv(int a, int b)
{
    a += MAXN; b += MAXN;
    int ans = 0;
    while (a<=b)
    {
        if (a%2==1) ans += idx[a++];
        if (b%2==0) ans += idx[b--];
        a /= 2; b /= 2;
    }
    return ans;
}
void addv(int a, int v)
{
    a += MAXN; idx[a] += v;
    while (a = a/2)
        idx[a] = idx[2*a]+idx[2*a+1];
}
vector<int> in[MAXN];
vector<int> factors[MAXN];
vector<int> out[MAXN];
int dans[MAXN];
int ans[MAXN];
int main()
{
    int N, M; scanf("%d%d", &N, &M);
    for(int i=1; i<=M; ++i)
        for(int j=i; j<=M; j+=i)
            factors[j].push_back(i);
    for(int i=0; i<N; ++i)
    {
        int L, R; scanf("%d%d", &L, &R);
        in[L].push_back(R-L+1);
        out[R].push_back(R-L+1);
        dans[R-L+1]++;
    }
    for(int i=M; i>=1; --i)
        ans[i] = ans[i+1]+dans[i];
    for(int i=1; i<=M; ++i)
    {
        for (auto x: in[i]) addv(x, 1);
        for (auto x: factors[i]) ans[x] += getv(1, x-1);
        for (auto x: out[i]) addv(x, -1);            
    }
    for(int i=1; i<=M; ++i)
        printf("%d\n", ans[i]);
    return 0;
}









