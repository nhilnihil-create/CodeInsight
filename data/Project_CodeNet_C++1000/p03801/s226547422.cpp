#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include <fstream>
#include <time.h>
#include <iterator>
#include<random>



#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 500050;



set<int>st;
vector<int>idx;
int ans[100010],cum[100010];
vector<int>v;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	v.pb(0);
	REP(i, N) {
		int a; cin >> a;
		v.pb(a);
	}
	int mx = -1;
	REP(i, N+1) {
		if (v[i] > mx) {
			st.insert(v[i]);
			idx.pb(i);
			mx = v[i];
		}
	}
	VSORT(v);
	auto itr = st.find(mx);
	vector<int>res;
	bool debug = 0;
	REPR(i, N) {
		cum[i] = cum[i + 1] + v[i];
		if(debug)printf("*itr:%lld i:%lld cum[i]:%lld v[i]%lld\n",*itr, i, cum[i], v[i]);
		if (v[i] == *itr) {
			res.pb(cum[i] - v[i] * (N - i+1));
			itr--;
		}
	}
	VREVERSE(res);
	
	if (debug) {
		REP(i, res.size()) {
			pe(res[i]);
		}
		cout << endl;
	}
	REP(i, res.size() - 1) {
		res[i] -= res[i + 1];
		ans[idx[i+1]] = res[i];
	}
	FOR(i, 1, N + 1) {
		print(ans[i]);
	}
}
