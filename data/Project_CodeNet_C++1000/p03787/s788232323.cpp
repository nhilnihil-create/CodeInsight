#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <iomanip>
#include <utility>
#include <functional> 

using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define X first
#define Y second
#define rg register
#define il inline
#define lch(x) ((x)<<1)
#define rch(x) ((x)<<1^1)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep0(i,n) for(register int (i)=0;(i)<(n);++(i))
#define rep(i,st,ed) for(register int (i)=(st);(i)<=(ed);++(i))
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double dbl;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> inline T qmin(const T a,const T b) {return a<b?a:b;}
template<typename T> inline T qmax(const T a,const T b) {return a>b?a:b;}
template<typename T> inline void getmin(T &a,const T b) {if(a>b) a=b;}
template<typename T> inline void getmax(T &a,const T b) {if(a<b) a=b;}

inline void fileio(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int inf=1e9+7;
const ll linf=1e17+7;
const int N=1e5+107,M=4e5+107;

int v[M],nxt[M],m;
int head[N],used[N],n;
ll cnt1,cnt2,cnt3;//1-bipartite 2-not_bipartite 3-single vertices

il void addedge(int p,int x,int y){
	v[p]=y,nxt[p]=head[x],head[x]=p;
}

il bool dfs(int u,int c){
	used[u]=c;
	bool ans=true;
	for(int e=head[u];e;e=nxt[e]){
		if(used[v[e]]){
			if(c+used[v[e]]!=3) ans=false;
		}else{
			ans&=dfs(v[e],3-c);
		}
	}
	return ans;
} 

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(lch(i),x,y);
		addedge(rch(i),y,x); 
	}
	for(int i=1;i<=n;++i){
		if(used[i]) continue;
		if(dfs(i,1)){
			if(head[i]) ++cnt1;else ++cnt3;
		}else{
			++cnt2;
		}
	}
//	cerr<<cnt1<<endl<<cnt2<<endl<<cnt3<<endl;
	printf("%lld\n",(2*cnt3*n-cnt3*cnt3)+(2*cnt1*cnt1)+(cnt2*cnt2+2*cnt1*cnt2)); 
	return 0;
} 