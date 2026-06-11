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

#define Pr(f,...) fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)

template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

deque<int> f(long long n){
	if(n==1) return deque<int>();
	if(n&1){
		deque<int> q=f(n-1); 
		q.push_front((int)q.size()+1); 
		return q;
	}else{
		deque<int> q=f(n/2); 
		q.push_back((int)q.size()+1); 
		return q;
	}
}

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin);
	//freopen("my.out","w",stdout);
#endif
	long long n;
	cin>>n;
	auto ans=f(n+1); 
	printf("%d\n",(int)ans.size()*2);
	for(int x:ans)printf("%d ",x);
	rep(i,1,(int)ans.size())printf("%d ",i);
	puts(""); 
	return 0;
}