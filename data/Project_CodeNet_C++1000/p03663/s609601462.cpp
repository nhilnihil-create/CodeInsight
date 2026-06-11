#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<iomanip>
#include<utility>
using namespace std;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define rg register
#define il inline
#define lch(x) ((x)<<1)
#define rch(x) ((x)<<1^1)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep0(i,n) for(register int i=0;i<(n);++i)
#define per0(i,n) for(register int i=(n)-1;i>=0;--i)
#define rep(i,st,ed) for(register int i=(st);i<=(ed);++i)
#define per(i,ed,st) for(register int i=(ed);i>=(st);--i)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double dbl;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> il T qmin(const T &a,const T &b){return a<b?a:b;}
template<typename T> il T qmax(const T &a,const T &b){return a>b?a:b;}
template<typename T> il void getmin(T &a,const T &b){if(a>b) a=b;}
template<typename T> il void getmax(T &a,const T &b){if(a<b) a=b;}
il void fileio(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int inf=(int)1e9+7;
const ll linf=(ll)1e17+7;

il ll val(int p){
	ll ans=1;
	while(p--) ans=ans*10;
	return ans;
}

il void ask(ll v){
	printf("? %lld\n",v);
	fflush(stdout);
}

il bool ans(){
	char tmp[4];
	scanf("%s",tmp);
	return tmp[0]=='Y';
}

int main(){
	ask((ll)1e18);
	if(ans()){
		//10^n
		int ul=1,ur=9;
		while(ul<=ur){
			int mid=ul+ur>>1;
			ask(val(mid)-1);
			if(ans()) ur=mid-1;else ul=mid+1;
		}
		printf("! %lld\n",val(ur));
		return 0;
	}
	//calc w
	int ul=1,ur=9;
	while(ul<=ur){
		int mid=ul+ur>>1;
		ask(val(mid-1));
		if(ans()) ul=mid+1;else ur=mid-1; 
	}
	int w=ur,res=val(ur)-1;//位数
	per0(i,w){
		ll ul=(i==w-1?1:0),ur=9;
		while(ul<=ur){
			ll mid=ul+ur>>1;
			ask(res*val(9)-(9-mid)*val(i+9)+999999999);
			if(ans()) ur=mid-1;else ul=mid+1;
		}
		res-=(9-ul)*val(i);
	}
	printf("! %d\n",res);
	return 0;
}
