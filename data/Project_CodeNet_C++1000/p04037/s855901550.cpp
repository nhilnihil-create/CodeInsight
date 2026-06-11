#include <bits/stdc++.h>
#define pb push_back
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

int n,a[N],win;

int main(int argc,char *argv[]){
	//freopen("dat.in","r",stdin); 
	read(n); 
	rep(i,1,n)read(a[i]); 
	sort(a+1,a+n+1,greater<int>()); 
	rep(i,1,n){
		if(i+1>a[i+1]){
			win|=(a[i]-i)&1;
            if(win)break;
			rep(j,i+1,n)if(a[j]==i)win^=1;else break;
			break;
		}
	}
	puts(win?"First":"Second"); 
}
