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

const int N=1e5+7,Node=N<<2;
const int mod=1000000007;

int a[N],val[N],n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	a[0]=-1;
	for(int i=1,cur=n,j;i<=n;i=j,--cur){
		int begin=2*(i-1-(n-cur));
	//	cerr<<"begin="<<begin<<endl;
		for(j=i;j<=n&&(j==i||a[j-1]-begin+1>=2*(j-i));++j){
			val[j]=cur;
		}
	}
	ll ans=1;
//	for(int i=1;i<=n;++i) eprintf("%d ",val[i]);eprintf("\n");
	for(int i=1;i<=n;++i) ans=ans*(ll)(val[i]-n+i)%mod;
	printf("%lld\n",ans);
	return 0;
} 