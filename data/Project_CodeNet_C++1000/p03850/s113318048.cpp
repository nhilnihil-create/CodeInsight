#include <bits/stdc++.h>
using namespace std;
#define LL long long
inline LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f;
}
signed main(){
	int n=read();
	LL x=0,y,z=y=-10000000000000ll;
	for (int i=1;i<=n;++i){
		LL p=read();x+=p;y-=p;z+=p;
		if (p<0){
			z=max(y,z);y=max(x,y);
		}
		x=max(x,y);y=max(y,z);
	}
	cout<<x<<endl;
	return 0;
}
