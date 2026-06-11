#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())
#define all(a) (a).begin(), (a).end()

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;


int main(void){

	int n; cin >> n;

	vector<int> a(n);
	REP(i,n) cin >> a[i];

	map<int, int> mp;
	REP(i,n){
		if(a[i] >= 3200) mp[8]++;
		else mp[a[i]/400]++;
	}

	int ans = 0;
	int c = 0;
	for(auto a:mp){
		int idx = a.first;
		int cnt = a.second;
		if(idx < 8) ans++;
		else c += cnt;
	}

	printf("%d %d\n", max(ans, 1), ans+c);

	return 0;

}
