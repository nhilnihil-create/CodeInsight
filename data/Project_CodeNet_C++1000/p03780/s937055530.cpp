#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));

int a[5010] = {}, n, k;
bool dp[5010] = {};

bool c(int t){
	bool dp[5010] = {}; dp[0] = true;
	
	REP(i,0,n){
		if(i == t) continue;
		RREP(j,5000,0) if(j - a[i] >= 0) dp[j] |= dp[j - a[i]];
	}
	
	REP(i,max(0, k - a[t]), k) if(dp[i]) return false;
	return true;
}

int binary(){
	int ok = -1, ng = n;
	
	while(abs(ok - ng) > 1){
		int mid = (ok + ng) / 2;
		if(c(mid)) ok = mid;
		else ng = mid;
	}
	
	return ok + 1;
}

int main(){
	cin >> n >> k;
	REP(i,0,n) cin >> a[i]; sort(a, a+n);
	
	cout << binary() << endl;
	return 0;
}
//k-a[i] 以上 k 未満 の集合が作れる -> Need
