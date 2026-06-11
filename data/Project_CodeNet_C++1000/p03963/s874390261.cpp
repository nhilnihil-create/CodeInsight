#include<cstdio>
using namespace std;
int main()
{
    int n,k,ans;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        ans=k;
        while(--n)
        {
            ans*=k-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
