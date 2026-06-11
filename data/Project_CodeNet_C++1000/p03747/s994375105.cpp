#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define mem(a,k) memset(a,k,sizeof(a))
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

#define Pr(f,...) //fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)

typedef long long ll;

template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

const int N=1e5+50;

ll n,L,T,o;
vector<ll> p;

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin);
	//freopen("my.out","w",stdout);
#endif
	read(n),read(L),read(T); 
	lop(i,0,n){
		ll x,w; 
		read(x),read(w); 
		if(w==1)x+=T,o+=x/L,p.pb(x%L);
		else{
			x-=T,o+=x/L,x%=L;
			if(x<0)x+=L,--o;
			p.pb(x);
		}
	}
	o=(o%n+n)%n;
	sort(all(p)); 
	lop(i,0,n)printf("%lld\n",p[(i+o)%n]);
	return 0;
}