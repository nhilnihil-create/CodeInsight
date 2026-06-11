#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=n-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

/*
 貪欲
 ①決定問題 必ず解に含まれる(含むように変換できる)ものから決めていく みんプロ本選B
 ②最適化問題 任意の解から評価を落とさず解に含められるようなものから決めていく 区間スケジューリングとか
 ③
 */

/*
 DP
 ①DPはある程度決め打ちをするべき(解を帰納的に構成できないか？)
 */

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	ll lb=0,ub=n+1;
	while(ub-lb>1) {
		ll mid=(lb+ub)/2;
		if(mid*(mid+1)/2<n) lb=mid;
		else ub=mid;
	}
	REP(i,ub) {
		if(i+1==ub*(ub+1)/2-n) continue;
		else cout<<i+1<<endl;
	}
}
