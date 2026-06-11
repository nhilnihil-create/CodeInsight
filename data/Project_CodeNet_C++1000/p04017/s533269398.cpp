#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6;
int n,L,T;
int pos[N];
int f[N][35];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main() 
{
    n=read(); 
    for(int i=1;i<=n;i++) pos[i]=read();
    L=read(),T=read();
    for(int i=1;i<=n;i++)
        f[i][0]=upper_bound(pos+1,pos+n+1,pos[i]+L)-pos-1;
    for(int j=1;j<=30;j++)
    	for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
    while(T--) 
	{
		int st=read(),en=read();
        if(st>en) swap(st,en);
        int ans=0;
        for(int i=30;i>=0;i--)
		 {
            if(f[st][i]<en)
			{
                ans+=1<<i;
                st=f[st][i];
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}