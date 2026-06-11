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
const int N=1e5+7;
 
int a[N],n;
 
il bool calc(){
	int tot=0,num;
	rep(i,1,n){
		tot+=(~a[i]&1);
		if(a[i]&1) num=a[i];
	}
	if(tot!=n-1){
		return tot&1;
	}else{
		if(num==1) return tot&1;
		if(~n&1) return true;
		rep(i,1,n) a[i]/=2;
		int g=a[1];
		rep(i,2,n) g=__gcd(a[i],g);
		rep(i,1,n) a[i]/=g;
		return calc()^1;
	}
}
 
int main(){
	scanf("%d",&n);
	int tot=0;
	rep(i,1,n) scanf("%d",a+i),tot+=(~a[i]&1);
	puts(calc()?"First":"Second");
	return 0;
}