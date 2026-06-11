#include<map>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long
#define REP(i,e,s) for(register ll i=e; i<=s; i++)
#define DREP(i,e,s) for(register ll i=e; i>=s; i--)

#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define int ll
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

struct edge {
	int x,y;
} a[MAXN];

int ans[10];

map<pair<int,int>,int> mp;

signed main() {
	int h=read(),w=read(),n=read();

	REP(i,1,n) {
		int x=read(),y=read();
		REP(i,max(1ll,x-2),min(h-2,x)) REP(j,max(1ll,y-2),min(w-2,y)) mp[make_pair(i,j)]++;
	}	

	map<pair<int,int>,int>:: iterator iter;
	iter=mp.begin();
	while(iter!=mp.end()) {
		ans[iter->second]++;
		iter++;
	}

	int ans0=(h-2)*(w-2);

	REP(i,1,9) ans0-=ans[i];

	printf("%lld\n",ans0);
	REP(i,1,9) printf("%lld\n",ans[i]);

	return 0;
}