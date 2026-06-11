#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));

priority_queue<ll> que[100001];
vector<ll> dp(100001, -1);

ll solve(long long n){
	if (dp[n] != -1) return dp[n];
	if (que[n].empty()) return dp[n] = 0;
	// cout << que[n].top() << " ";
	priority_queue<ll> quel;
	while (!que[n].empty()) {
		quel.push(solve(que[n].top()));
		que[n].pop();
	}
	ll res = 0, c = 1;
	while (!quel.empty()) {
		// cout << quel.top() << " ";
		res = max(res, quel.top()+c);
		// cout << solve(quel.top()) << endl;
		quel.pop();
		c++;
	}
	// cout << endl;
	return dp[n] = res;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> a(N-2+1);
	for(int i = 0 ; i <= N-2 ; i++){
		scanf("%lld",&a[i]);
		a[i]--;
		que[a[i]].push(i+1);
	}
	// rep(i, N) {
	// 	cout << i << ": ";
	// 	while(!que[i].empty()) {
	// 		cout << que[i].top() << " ";
	// 		que[i].pop();
	// 	}
	// 	cout << endl;
	// }
	cout << solve(0) << endl;
	return 0;
}

