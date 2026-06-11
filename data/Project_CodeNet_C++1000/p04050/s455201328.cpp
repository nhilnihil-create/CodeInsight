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

vector<int> od,ev;
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int a;
		scanf("%d",&a);
		if(a&1) od.pb(a);
		else ev.pb(a); 
	} 
	if(od.size()>2){
		puts("Impossible");
	}else if(!od.size()){
		rep0(i,ev.size()) printf("%d ",ev[i]);puts("");
		printf("%d\n%d ",m+1,ev[0]-1);
		rep(i,1,ev.size()-1) printf("%d ",ev[i]);puts("1");
	}else if(od.size()==1){
		printf("%d ",od[0]);
		rep0(i,ev.size()) printf("%d ",ev[i]);puts("");
		printf("%d\n",m+(od[0]>1));
		if(od[0]>1) printf("%d ",od[0]-1);
		rep0(i,ev.size()) printf("%d ",ev[i]);puts("1");
	}else{
		printf("%d ",od[0]);
		rep0(i,ev.size()) printf("%d ",ev[i]);
		printf("%d\n",od[1]);
		printf("%d\n",m-(od[0]==1));
		if(od[0]>1) printf("%d ",od[0]-1);
		rep0(i,ev.size()) printf("%d ",ev[i]);
		printf("%d\n",od[1]+1);
	}
	return 0;
}
