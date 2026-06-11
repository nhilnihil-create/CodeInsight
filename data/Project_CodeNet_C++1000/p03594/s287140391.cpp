#include<bits/stdc++.h>
#include<bitset>
typedef long long LL;
typedef double DB;
#define REP(i,s,t) for(register int i=s;i<=t;++i)
#define PER(i,s,t) for(register int i=s;i>=t;--i)
#define FOREDGE(i,x,v) for(int i=fir[x],v=to[i];i;i=nex[i],v=to[i])
template<typename T>inline T in(){
    T ans=0;bool b=0;char ch=getchar();
    while(ch<'0'||ch>'9')b=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')ans=ans*10+ch-48,ch=getchar();
    return b?-ans:ans;
}
#define II in<int>()
#define IL in<LL>()
//<-----QAQ----->
int n,m,d;
char ch[5]="RYGB";
int main(){
    n=II,m=II,d=II;
    REP(i,1,n){
        REP(j,1,m){
            int x=((m+i+j)/d)&1,y=((m+i-j)/d)&1;
            putchar(ch[x*2+y]);
        }
        puts("");
    }
}