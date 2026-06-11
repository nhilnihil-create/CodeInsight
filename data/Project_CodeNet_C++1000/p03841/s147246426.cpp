#include<bits/stdc++.h>
using namespace std;

namespace IO
{
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
    char obuf[S],*oS=obuf,*oT=oS+S-1,qu[55];int qr;
    inline void flush(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
    inline void putc(char x){*oS++ =x;if(oS==oT) flush();}
    template <class I>inline void print(I x)
    {
        if(!x) putc('0');
        while(x) qu[++qr]=x%10+'0',x/=10;
        while(qr) putc(qu[qr--]);
    }
    inline void prints(const char *s)
    {
        int len=strlen(s);
        for(int i=0;i<len;i++) putc(s[i]);
        putc('\n');
    }
}

using namespace IO;
const int N=510;
int a[N*N],X[N],n;
int c[N],cnt[N];
int pos[N][N],num[N];

bool cmp(const int &x,const int &y){return X[x]<X[y];}

bool check()
{
    for(int i=1;i<=n*n;i++)
        pos[a[i]][++num[a[i]]]=i;
    for(int i=1;i<=n;i++)
        if(pos[i][i]!=X[i]) return 0;
    return 1;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) X[i]=read();
    for(int i=1;i<=n;i++) c[i]=i,a[X[i]]=i;
    sort(c+1,c+1+n,cmp);
    for(int i=1;i<=n;i++) cnt[i]=i-1;
    for(int i=1;i<=n*n;i++)
    {
        if(a[i]) continue;
        for(int j=1;j<=n;j++)
            if(cnt[c[j]]){a[i]=c[j];cnt[c[j]]--;break;}
    }
    for(int i=1;i<=n;i++) cnt[i]=n-i;
    for(int i=n*n;i>=1;i--)
    {
        if(a[i]) continue;
        for(int j=n;j>=1;j--)
            if(cnt[c[j]]){a[i]=c[j];cnt[c[j]]--;break;}
    }
    if(check())
    {
        prints("Yes");
        for(int i=1;i<=n*n;i++)
            print(a[i]),putc(' ');
    }
    else prints("No");
    flush();
    return 0;
}