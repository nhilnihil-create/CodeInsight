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

vector<int> solve(ll n) {
	if(n==1) return vector<int>();
	if(n%2==1) {
		vector<int> ret=solve(n-1);
		ret.insert(ret.begin(),SZ(ret));
		return ret;
	} else {
		vector<int> ret=solve(n/2);
		ret.push_back(SZ(ret));
		return ret;
	}
}

ll n;

void run() {
	scanf("%lld",&n);
	vector<int> p=solve(n+1);
	vector<int> ret=p; REPSZ(i,p) ret.PB(i);
	printf("%d\n",SZ(ret));
	REPSZ(i,ret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}
