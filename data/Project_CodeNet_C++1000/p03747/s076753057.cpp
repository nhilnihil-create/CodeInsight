#include<bits/stdc++.h>
#define N 100001
using namespace std;
long long c;
int x[N],w[N],ans[N];
int main()
{
	int n,L,t;
    scanf("%d%d%d",&n,&L,&t);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(w[i]==2)w[i]=-1;
        int r=x[i]+w[i]*t;
        if(r>0) 
        {
        	(c+=r/L)%=n;
		}
        else if(r<0)
        {
        	(c+=(r+1)/L-1)%=n;
		}
        ans[i]=(r%L+L)%L;
    }
    sort(ans+1,ans+n+1);
    c=(c+n)%n;
    for(int i=c+1;i<=n;i++)
    {
        printf("%d\n",ans[i]);
    }
    for(int i=1;i<=c;i++)
    {
       printf("%d\n",ans[i]); 
    }
}