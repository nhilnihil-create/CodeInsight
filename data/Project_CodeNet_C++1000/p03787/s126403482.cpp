#include <bits/stdc++.h>
using namespace std;
namespace IO
{
    const int __S=(1<<20)+5;char __buf[__S],*__H,*__T;
    inline char getc()
    {
        if(__H==__T) __T=(__H=__buf)+fread(__buf,1,__S,stdin);
        if(__H==__T) return -1;return *__H++;
    }
    template <class __I>inline void read(__I &__x)
    {
        __x=0;int __fg=1;char __c=getc();
        while(!isdigit(__c)&&__c!='-') __c=getc();
        if(__c=='-') __fg=-1,__c=getc();
        while(isdigit(__c)) __x=__x*10+__c-'0',__c=getc();
        __x*=__fg;
    }
    inline void readd(double &__x)
    {
        __x=0;double __fg=1.0;char __c=getc();
        while(!isdigit(__c)&&__c!='-') __c=getc();
        if(__c=='-') __fg=-1.0,__c=getc();
        while(isdigit(__c)) __x=__x*10.0+__c-'0',__c=getc();
        if(__c!='.'){__x=__x*__fg;return;}else __c=getc();
        double __t=1e-1;while(isdigit(__c)) __x=__x+1.0*(__c-'0')*__t,__t=__t*0.1,__c=getc();
        __x=__x*__fg;
    }
    inline void reads(char *__s,int __x)
    {
        char __c=getc();int __tot=__x-1;
        while(__c<'a'||__c>'z') __c=getc();
        while(__c>='a'&&__c<='z') __s[++__tot]=__c,__c=getc();
        __s[++__tot]='\0';
    }
    char __obuf[__S],*__oS=__obuf,*__oT=__oS+__S-1,__c,__qu[55];int __qr;
    inline void flush(){fwrite(__obuf,1,__oS-__obuf,stdout);__oS=__obuf;}
    inline void putc(char __x){*__oS++ =__x;if(__oS==__oT) flush();}
    template <class __I>inline void print(__I __x)
    {
        if(!__x) putc('0');
        if(__x<0) putc('-'),__x=-__x;
        while(__x) __qu[++__qr]=__x%10+'0',__x/=10;
        while(__qr) putc(__qu[__qr--]);
    }
    inline void prints(const char *__s,const int __x)
    {
        int __len=strlen(__s+__x);
        for(int __i=__x;__i<__len+__x;__i++) putc(__s[__i]);
    }
    inline void printd(long double __x,int __d)
    {
        long long __t=(long long)floor(__x);print(__t);putc('.');__x-=(double)__t;
        while(__d--)
        {
            long double __y=__x*10.0;__x*=10.0;
            int __c=(int)floor(__y+1e-9);if(__c==10) __c--;
            putc(__c+'0');__x-=floor(__y);
        }
    }
    inline void el(){putc('\n');}inline void sp(){putc(' ');}
}using namespace IO;
int n,m,x,y,gg,col[100005],vis[100005],d[100005],a,b,c;long long ans;vector<int>e[100005];
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<e[x].size();i++)
	{
		if(vis[e[x][i]]&&col[e[x][i]]==col[x]) gg=0;
		if(!vis[e[x][i]]) col[e[x][i]]=col[x]^1,dfs(e[x][i]);
	}
}
int main()
{
	read(n);read(m);for(int i=1;i<=m;i++) read(x),read(y),e[x].push_back(y),e[y].push_back(x),d[x]++,d[y]++;
	for(int i=1;i<=n;i++) if(!vis[i]){if(!d[i]){a++,vis[i]=1;continue;}gg=1;dfs(i);if(gg) b++;else c++;}
	print(2ll*a*n-1ll*a*a+2ll*b*b+2ll*b*c+1ll*c*c);flush();
}