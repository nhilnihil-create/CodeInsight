#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000000000;

ll n=-1; int nq;
bool query(ll x) {
	if(x==0) return true;
	if(x<=0||x>=1000000000000000000LL) printf("n=%lld, err\n",n);
	++nq;
	if(n==-1) {
		printf("? %lld\n",x); fflush(stdout);
		char res; scanf(" %c",&res); return res=='Y';
	} else {
		char a[20],b[20];
		sprintf(a,"%lld",n); sprintf(b,"%lld",x);
		bool xa=x<=n;
		bool xb=strcmp(b,a)<=0;
		bool ret=xa&&xb||!xa&&!xb;
		//printf("? %lld = %c (%d,%d)\n",x,ret?'Y':'N',x<=n?1:0,strcmp(b,a)<=0?1:0); fflush(stdout);
		return ret;
	}
}

ll solve() {
	ll l=1;
	while(l*10<=MAXN) l*=10;
	if(query(l)&&query(10*l)&&query(l-1)) {
		l=1;
		while(!query(l+1)) l*=10;
		return l;
	}
	while(true) {
		if(!query(l-1)) break;
		if(!query(l)) { l/=10; continue; }
		break;
	}
	ll r=min(10*l,(ll)MAXN+1);
	while(l+1<r) {
		ll m=l+(r-l)/2;
		if(!query(10*(m-1))) l=m; else r=m;
	}
	return l;
}

void run() {
	printf("! %lld\n",solve());
}

void test() {
	scanf("%lld",&n);
	printf("! %lld\n",solve());
}

void stress() {
	int mxq=0;
	for(n=1;n<=10000;++n) {
		nq=0;
		ll have=solve();
		if(have!=n) { printf("err %lld\n",n); }
		if(nq>mxq) mxq=nq;
	}
	for(ll bn=1;bn<=MAXN;bn*=10) {
		for(int j=-100;j<=+100;++j) {
			n=bn+j; if(n<1||n>MAXN) continue;
			nq=0;
			ll have=solve();
			if(have!=n) { printf("err %lld\n",n); }
			if(nq>mxq) mxq=nq;
		}
	}
	REP(i,1000) {
		ll bn=rand()%1000*1000000+rand()%1000*1000+1;
		REP(t,2) REP(j,100) {
			if(t==0) n=bn+j; else n=bn+1000-j-1; nq=0;
			ll have=solve();
			if(have!=n) { printf("err %lld\n",n); }
			if(nq>mxq) mxq=nq;
		}
	}
	printf("mxq=%d\n",mxq);
}

int main() {
	run();
	//test();
	//stress();
	return 0;
}
