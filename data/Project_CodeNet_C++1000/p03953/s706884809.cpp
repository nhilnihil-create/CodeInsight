#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long lint;
const int N=1e5+5;
int n,m,cf[N],val[N],nxt[62][N],ans[N];
lint q;

template <class T> inline T nxi(){
	T x=0;
	char c;
	while(((c=getchar())>'9'||c<'0')&&c!='-');
	const bool f=c=='-'&&(c=getchar());
	while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
	return f?-x:x;
}

int main(){
	n=nxi<int>();
	for(int i=1; i<=n; ++i){
		val[i]=nxi<int>();
		nxt[0][i]=i;
		cf[i]=val[i]-val[i-1];
	}
	m=nxi<int>(),q=nxi<lint>();
	for(int i=1; i<=m; ++i){
		const int x=nxi<int>();
		std::swap(nxt[0][x],nxt[0][x+1]);
	}
	for(int i=1; i<62; ++i){
		for(int j=1; j<=n; ++j){
			nxt[i][j]=nxt[i-1][nxt[i-1][j]];
		}
	}
	for(int i=1; i<=n; ++i){
		int tmp=i;
		for(int j=61; ~j; --j){
			if(q>>j&1) tmp=nxt[j][tmp];
		}
		ans[i]=cf[tmp];
	}
	lint sum=0;
	for(int i=1; i<=n; ++i){
		printf("%lld\n",sum+=ans[i]);
	}
	return 0;
}