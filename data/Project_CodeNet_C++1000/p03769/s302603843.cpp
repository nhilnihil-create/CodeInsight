#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long LL;
const int maxn=110;
int ans[maxn*2];
int main()
{
    LL n;
    cin>>n;
    n++;
    int tot=0;
    int w=0;
    while((n>>w)>1)w++;
    int cnt=0;
    while(w>0)
    {
        ans[++tot]=++cnt;
        w--;
        if((n>>w)&1)
        {
            ++tot;
            for(int i=tot;i>1;i--) ans[i]=ans[i-1];
            ans[1]=++cnt;
        }
    }
    printf("%d\n",cnt*2);
    for(int i=1;i<=cnt;i++) printf("%d ",i);
    for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
    return 0;
}
