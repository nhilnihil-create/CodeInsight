#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,t;

int a[100005];
int maxx[100005];
int minus[100005],ans;

int main()
{
    scanf("%d%d",&n,&t);
    int cnt=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    maxx[n]=a[n];
    for(int i=n-1;i>=1;i--)
        maxx[i]=max(maxx[i+1],a[i]);
    for(int i=1;i<=n-1;i++)
    {
        minus[i]=maxx[i+1]-a[i];
        ans=max(ans,minus[i]);
    }
    for(int i=1;i<=n;i++)
        if(minus[i]==ans)
            cnt++;
    printf("%d\n",cnt);
}