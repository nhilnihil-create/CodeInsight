#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(long long i=(a);((a)<(b)?i<=(b):i>=(b));((a)<(b)?++i:--i))
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   cerr<<#x<<": "<<(x)<<endl
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

template<typename Type,typename Type_k>
Type ipow(Type n,Type_k k){//n^k. O(log n).
	if(k==0) return 1;
	Type res=ipow(n*n,k/2);
	if(k&1) res*=n;
	return res;
}

template<typename Type,typename Type_k>
llong nCk(Type n,Type_k k){
	if(n-k<k) k=n-k;
	llong res=1LL;
	REP(i,k) res=res*(n-i)/(i+1);
	return res;
}

int main(){//Refering other editorials.
	int n,p;
	cin>>n>>p;
	
	int cnt[2]={};
	REP(i,n){
		int a;
		cin>>a;
		cnt[a&1]++;
	}
	
	llong ans;
	llong tmp=ipow(2LL,cnt[0]);
	if(p==0){
		llong tmpp=0LL;
		for(int i=0;i<=cnt[1];i+=2) tmpp+=nCk(cnt[1],i);
		debug(tmpp);
		ans=tmp*tmpp;
	}else{
		if(cnt[1]==0) ans=0LL;
		else{
			llong tmpp=0LL;
			for(int i=1;i<=cnt[1];i+=2) tmpp+=nCk(cnt[1],i);
			debug(tmpp);
			ans=tmp*tmpp;
		}
	}
	
	cout<<ans<<endl;
}