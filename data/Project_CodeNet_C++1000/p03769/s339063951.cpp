#include<cstdio>
#include<deque>
using namespace std;
typedef long long LL;
int t=1;
deque<int> q;
void dfs(LL n)
{
    if(n==1) return;
    if((n-1)%2==0)
    {
        dfs((n-1)/2);
        q.push_back(++t);
    }
    else
    {
        dfs(n-1);
        q.push_front(++t);
    }
}
int main()
{
    LL n;
    int i,m;
    scanf("%lld",&n);
    q.push_back(1);
    dfs(n);
    m=q.size();
    printf("%d\n",m*2);
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop_front();
    }
    for(i=1;i<=m;i++)
        printf("%d ",i);
    printf("\n");
    return 0;
}