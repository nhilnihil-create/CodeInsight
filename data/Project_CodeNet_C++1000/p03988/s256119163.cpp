#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define RG register
using namespace std;
const int N=103;
int n,a[N],maxx,num[N];
template<typename I> inline void read(I &ot){
    I ch=getchar(), x=0, f=1;
    while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();	}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();	}
    ot=x*f;}
template<typename I, typename... U> inline void read(I &x,U&... y){read(x); read(y...);}
template<typename I>inline I mx(const I&a,const I&b){return a>b ? a : b;}
inline void endd(){printf("Impossible\n"); exit(0);}
int main()
{
    //freopen("Tree Restoring.in","r",stdin);
    read(n);
    for(RG int i=1;i<=n;i++) read(a[i]), maxx=mx(maxx,a[i]), num[a[i]]++;
    if(maxx&1)
    {
        for(RG int i=maxx-maxx/2;i<=maxx;i++) if((num[i]-=2)<0) endd();
        for(RG int i=maxx-maxx/2;i;i--) if(num[i]) endd();
    }
    else {
        num[maxx/2]--;
        for(RG int i=maxx/2+1;i<=maxx;i++) if((num[i]-=2)<0) endd();
        for(RG int i=maxx/2;i;i--) if(num[i]) endd();
    }
    printf("Possible\n");
    return 0;
}