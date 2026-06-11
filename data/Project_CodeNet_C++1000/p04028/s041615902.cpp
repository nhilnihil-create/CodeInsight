#include<bits/stdc++.h>
#define MN 5000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int f[MN+5][MN+5],n,m;
char s[MN+5];
inline void R(int&x,int y){(x+=y)>=mod?x-=mod:0;}
int main()
{  
    n=read();scanf("%s",s+1);m=strlen(s+1);
    f[0][0]=1;
    for(int i=1;i<=m;++i) f[0][0]=1LL*f[0][0]*(mod+1)/2%mod;
    for(int i=1;i<=n;++i) for(int j=0;j<=i;++j)
        if(f[i-1][j]) R(f[i][j+1],2*f[i-1][j]%mod),R(f[i][max(0,j-1)],f[i-1][j]);
    printf("%d\n",f[n][m]);
    return 0;
}