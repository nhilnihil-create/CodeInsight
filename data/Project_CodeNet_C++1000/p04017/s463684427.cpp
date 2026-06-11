#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rg register
using namespace std;
inline int read(){
	rg int x=0; 
	rg char c=getchar();
	while(c<'0'||c>'9') 
		c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
const int N=1e5+5;
int l,n,q,x[N],a,b;
int pre[N][20],ans;
inline int get_power(int k){
	int ans=1;
	while(k--) 
		ans<<=1;
	return ans;
}
void prework(){
	for(rg int i(0);i<n;++i)
		pre[i][0]=upper_bound(x,x+n,x[i]+l)-x-1;
	for(rg int i(1);i<20;++i)
		for(rg int j(0);j<n;++j)
			pre[j][i]=pre[pre[j][i-1]][i-1];
}
int main(){
	n=read();
	for(rg int i(0);i<n;++i)
		x[i]=read();
	l=read();
	prework();
	q=read();
	while(q--){
		a=read();
		b=read();
		ans=1;
		if(a>b)
			swap(a,b);
		--b; --a;
		while(pre[a][0]<b)
			for(rg int i(0);i<20;++i)
				if(pre[a][i]>=b){
					a=pre[a][i-1];
					ans+=get_power(i-1);
					break;
				}
		printf("%d\n",ans);
	}
	return 0;
}