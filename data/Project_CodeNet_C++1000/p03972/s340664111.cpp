// 間違ってJOI垢で提出していた…
const bool DEBUG = 1;
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <complex>
#include <random>
#include <iomanip>
#include <stdio.h>
#include <sys/time.h>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> IP;
typedef pair<P, P> PP;
typedef pair<int, PP> IPP;
typedef vector<int> VI;
typedef vector<P> VP;
 
#define omajinai ios::sync_with_stdio(false);cin.tie(0)
 
#define FOR(i,a,b) for(int i=(a);i<int(b);++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(b)-1;i>=int(a);--i)
#define RREP(i,n) RFOR(i,0,n)
 
#define LFOR(i,a,b) for(ll i=(a);i<(b);++i)
#define LREP(i,n) LFOR(i,0,n)
#define LRFOR(i,a,b) for(ll i=(b)-1;i>=(a);--i)
#define LRREP(i,b,a) LRFOR(i,0,n)
 
#define ALL(a) (a).begin(),(a).end()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
#define MP make_pair
#define PB push_back
#define EACH(i,c) REP(i,(int)(c).size())
#define REACH(i,c) RREP(i,(int)(c).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
#define BR cout << "\n"
 
#define dump(x) if(DEBUG)cerr<<"[" << __LINE__ << "] "<<#x<<"="<<(x)<<"\n"
#define dump2(x,y) if(DEBUG)cerr<<"["<<__LINE__<< "] "<<#x<<"="<<(x)\
			<<" , "<<#y<<"="<<(y)<<"\n"
#define dump3(x,y,z) if(DEBUG)cerr<<"["<<__LINE__<< "] "<<#x<<"="<<(x)\
			<<" , "<<#y<<"="<<(y)<<"\n"\
			<<" , "<<#z<<"="<<(z)<<"\n"
 
#define SAY(x) if(DEBUG) cerr << "[" << __LINE__ << "] " << (x) << "\n"
 
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;
 
ll ans;
 
int main() {
	omajinai;
	ll w,h;cin>>w>>h;
	VP v;
	REP(i,w){
		int p;
		cin>>p;
		v.PB(P(p, 0));
	}
	REP(i,h){
		int p;
		cin>>p;
		v.PB(P(p, 1));
	}
	SORT(v);
 
	int c[] = {0,0};
	ll ans = 0;
	for(auto e:v){
		int x = e.first, f = e.second;
		ans += (ll)x * ((f ? w+1 : h+1) - c[f]);
		c[!f]++;
	}
	cout << ans;
}
