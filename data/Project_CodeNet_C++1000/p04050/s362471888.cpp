#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
#define _rep(i,s,t) for(register int i=s;i>=t;--i)
#define Rep(i,s,t) for(register int i=s;i<t;++i)
#define go(x) for(register int e=las[x];e;e=nxt[e])
#define re register
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define gi(x) read(x)
#define gii(x,y) read(x),read(y)
#define giii(x,y,z) read(x),read(y),read(z)
#define ms(f,x) memset(f,x,sizeof f)
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
namespace IO{
    #define gc getchar()
    #define pc(x) putchar(x)
    template<typename T>inline void read(T &x){
        x=0;int f=1;char ch=gc;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
        while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=gc;x*=f;return;
    }
    template<typename T>inline void write(T x=0){
        T wr[51];wr[0]=0;if(x<0)pc('-'),x=-x;if(!x)pc(48);
        while(x)wr[++wr[0]]=x%10,x/=10;while(wr[0])pc(48+wr[wr[0]--]);
		putchar('\n');
		return;
    }
}
using IO::read;
using IO::write;
using namespace std;
#define gi(x) read(x)
typedef long long ll;
const int N=1e5+11;
int n,m;
int a[N],b[N],top;
int main(){
    gii(n,m);
    int odd1=-1,odd2=-1;
    rep(i,1,m){
        gi(a[i]);
        if(a[i]&1){
            if(odd1==-1)odd1=i;
            else if(odd2==-1)odd2=i;
            else{
				puts("Impossible");
                return 0;
            }
        }
    }
    if(m==1){
        if(a[1]==1)printf("1\n1\n1\n");
        else printf("%d\n2\n1 %d\n",a[1],a[1]-1);
        return 0;
    }
    if(odd1!=-1)swap(a[1],a[odd1]);
    if(odd2!=-1)swap(a[m],a[odd2]);
    rep(i,1,m)printf("%d%c",a[i]," \n"[i==m]);
    if(a[m]==1){
        printf("%d\n",m-1);
        printf("%d ",a[1]+1);
        rep(i,2,m-1)
            printf("%d ",a[i]);
        puts("");
        return 0;
    }
    b[1]=a[1]+1;
    rep(i,2,m-1)
        b[i]=a[i];
    b[m]=a[m]-1;
    printf("%d\n",m);
    rep(i,1,m)
        printf("%d%c",b[i]," \n"[i==m]);
    return 0;
}