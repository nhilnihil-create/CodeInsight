//#pragma GCC optimize ("-O3","unroll-loops")
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
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include <random>

using namespace std;

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
#define print(x) cout<<x<<'\n';
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ");
//#define double long double



template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }

int pa[100010], so[100010];
int num[100010];
int N, M;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	REP(i, N) {
		int x; cin >> x;
		num[x]++;
	}
	FOR(i, 1, 100001) {
		int cnt_pair = num[i] / 2;
		pa[i % M] += cnt_pair;
		so[i % M] += (num[i] & 1);
	}
	ll ans = 0;
	ans += so[0] / 2;
	ans += pa[0];
	//pe(0); print(ans);
	FOR(i, 1,M) {
		if (i == M - i) {
			ans += so[i] / 2;
			so[i] = (so[i] & 1);
			//pe(i)print(ans);
			continue;
		}
		int sol = min(so[i], so[(M - i)]);
		ans += sol;
		so[i] -= sol;
		so[M - i] -= sol;
		while(so[i]>0) {
			if (so[M - i] > 0) {
				ans++;
				so[M - i]--;
				so[i]--;
			}
			else if (pa[M - i] > 0) {
				ans++;
				pa[M - i]--;
				so[M - i]++;
				so[i]--;
			}
			else break;
		}
		//pe(i)print(ans);
	}
	FOR(i, 1, M) {
		ans += pa[i];
		//pe(i)print(ans);
	}
	print(ans);
}
