#include<bits/stdc++.h>
using namespace std;

const int S=(1<<20)+5;
char buf[S],*H,*T;
inline char Get()
{
    if(H==T) T=(H=buf)+fread(buf,1,S,stdin);
    if(H==T) return -1;return *H++;
}
inline int read()
{
    int x=0;char c=Get();
    while(!isdigit(c)) c=Get();
    while(isdigit(c)) x=x*10+c-'0',c=Get();
    return x;
}
inline int readopt()
{
    char c=Get();
    while(c!='+'&&c!='-') c=Get();
    return c;
}

typedef long long LL;
const int N=100010;
int num[N],n,k;
char opt[N];
LL f[2][3];

int main()
{
    n=read();
    num[0]=read();
    for(int i=1;i<n;i++)
    {
        opt[i]=readopt();
        num[i]=read();
    }
    f[k=0][0]=num[0];
    f[0][1]=f[0][2]=-(1ll<<60);
    for(int i=1;i<n;i++,k^=1)
    {
        if(opt[i]=='+')
        {
            f[k^1][0]=max(max(f[k][0],f[k][1]),f[k][2])+num[i];  //原地转移 或 拆1/2个括号
            f[k^1][1]=max(f[k][1],f[k][2])-num[i];  //原地转移 或 拆1个括号
            f[k^1][2]=f[k][2]+num[i];  //原地转移
        }
        else
        {
            f[k^1][0]=max(max(f[k][0],f[k][1]),f[k][2])-num[i];  //原地转移 或 拆1/2个括号
            f[k^1][1]=max(max(f[k][1],f[k][2])+num[i],f[k][0]-num[i]);  //原地转移 或 拆1个括号 或 添1个括号
            f[k^1][1]=max(max(f[k][1]-num[i],f[k][2]-num[i]),f[k^1][1]);  //拆1/2个括号又添1个括号
            f[k^1][2]=max(f[k][2]-num[i],f[k][1]+num[i]);  //原地转移 或 添1个括号
            f[k^1][2]=max(f[k][2]+num[i],f[k^1][2]);  //拆1个括号又添1个括号
        }
    }
    LL ans=max(max(f[k][0],f[k][1]),f[k][2]);
    printf("%lld\n",ans);
    return 0;
}