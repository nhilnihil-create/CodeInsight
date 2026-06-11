#include <cstdio>
#include <iostream>
#include <map>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
#define pi pair<int,int>
map <pi,int> mp;
const int inf(1e5+5);
int h=read(),w=read(),n=read(),i,j;
int cnt[10];
ll ans;
void init(){
	while (n--){
		int x=read(),y=read();
		for (i=max(1,x-2);i<=min(h-2,x);++i)
			for (j=max(1,y-2);j<=min(w-2,y);++j)
				++mp[pi(i,j)];
	}
}

signed main(){
	init();
	for (auto p:mp) cnt[p.second]+=1,n+=1;
	ans=1ll*(h-2)*(w-2);
	printf("%lld\n",ans-n-1);
	for (int i(1);i<=9;++i) printf("%d\n",cnt[i]);
	return 0; 
}
