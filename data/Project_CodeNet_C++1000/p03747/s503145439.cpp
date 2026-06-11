#include<bits/stdc++.h>
#define db double
#define ll long long
#define ev edge[i].v
#define INF 1000000007
#define pir pair<int,int>
#define Rep(i,l,r) for(int i=(l);i<=(r);++i)
#define RepD(i,r,l) for(int i=(r);i>=(l);--i)
#define RepG(i,x) for(int i=head[x];i;i=edge[i].next)
using namespace std;

const int N=1e5+5;

ll x[N];

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	ll n,l,t,w,num=0;
	scanf("%lld%lld%lld",&n,&l,&t);
    Rep(i,1,n){
        scanf("%lld%lld",&x[i],&w);
        x[i]+=w==1?t:-t;
		num+=x[i]/l-(x[i]%l<0);
        x[i]=(x[i]%l+l)%l;
    }
    sort(x+1,x+n+1);
    num=(num%n+n)%n;
    Rep(i,num+1,n) printf("%lld\n",x[i]);
    Rep(i,1,num) printf("%lld\n",x[i]);
	return 0;
}