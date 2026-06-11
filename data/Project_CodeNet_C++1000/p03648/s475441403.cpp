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

const int MAX = 1010;
const int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
typedef pair<int, int>P;

int dx[4] = { 1,0,-1,0 };//D,R,U,L
int dy[4] = { 0,1,0,-1 };


vector<int>ans;


signed main() {
	ll K; cin >> K;
	ans.resize(50);
	REP(i, 50) {
		ans[i] = i;
	}
	ll st = K / 50;
	ll rem = K - st * 50;
	REP(i, 50) {
		ans[i] += st;
	}
	while (rem > 0) {
		ll mn = INF;
		REP(i, 50) {
			mn = min(ans[i], mn);
		}
		int idx;
		REP(i, 50) {
			if (ans[i] == mn)idx = i;
		}
		REP(i, 50) {
			if (i == idx) {
				ans[i] += 50;
			}
			else ans[i]--;
		}
		rem--;
	}
	print(50);
	REP(i, 50)pe(ans[i]);
	cout << endl;
}
