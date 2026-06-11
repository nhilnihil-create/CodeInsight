#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
    int q=0;char ch=' ';
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
    return q;
}
typedef long long LL;
const int N=100005;
LL sum,nowadd,nows,a[N],orz[N],m;int n;
int work() {
    int js=0;
    for(RI i=0;i<n;++i) {
        int b=a[i]-a[(i-1+n)%n];
        if((m-b)%n||m-b<0) return 0;
        orz[i]=(m-b)/n,js+=orz[i];
    }
    if(js!=m) return 0;
    for(RI i=0;i<n;++i) {
        nows+=orz[i],nowadd+=nows;
        if(a[i]<nowadd) return 0;
        a[i]-=nowadd;
    }
    for(RI i=0;i<n;++i) {
        nows-=orz[i],nowadd-=1LL*n*orz[i],nowadd+=nows;
        if(a[i]!=nowadd) return 0;
    }
    return 1;
}
int main()
{
    n=read();
    for(RI i=0;i<n;++i) a[i]=read(),sum+=a[i];
    if(sum%(1LL*(n+1)*n/2)) {puts("NO");return 0;}
    m=sum/(1LL*(n+1)*n/2);
    if(work()) puts("YES");
    else puts("NO");
    return 0;
}