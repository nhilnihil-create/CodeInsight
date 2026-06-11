#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(ll i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(ll i=(begin)-1;i>=(end);i--)
#define IREP(i, n) IFOR(i,n,0)
#define SORT(a) sort(a.begin(), a.end())
#define ISORT(a) sort(a.begin(), a.end(),greater<ll>())
#define REVERSE(a) reverse(a.begin(), a.end())
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=(" << v[0]; FOR(i_debug, 1, v.size()){ cout << "," << v[i_debug]; } cout << ")" << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;}
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)

#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define INF 1000000000000000000

using vec = vector<ll>;
using mat = vector<vec>;
using Pii = pair<ll, ll>;
using PiP = pair<ll, Pii>;
using PPi = pair<Pii, ll>;
using bvec = vector<bool>;
using Pvec = vector<Pii>;


template<typename T> void readv(vector<T> &a) { REP(i, a.size()) cin >> a[i]; }
void readv_m1(vector<int> &a) { REP(i, a.size()) {cin >> a[i]; a[i]--;} }

ll mod = 1000000007;

struct Tournament
{
	vec maxdepth;
	vec par;

	Tournament(ll N) { init(N); }//初期化

	void init(ll N) {
		maxdepth.resize(N);
		par.resize(N);
		// looser.resize(N);
		for (ll i = 0; i < N; i++) { maxdepth[i] = -1; par[i] = -1;}
	}

	void ComptDepth(mat& edge) {
		ll currentdepth = 0;
		ll maxdepthnow = -1;
		stack<ll> stack;
		stack.push(0);
		vec init(edge.size(), 0);
		ll ver = -1;
		bool pop = false;
		vector<bool> visited(edge.size(), false);
		while (!stack.empty()) {
			ver = stack.top();
			visited[ver] = true;
			// debug(ver);
			// debug(init[ver]);
			pop = true;

			if (edge[ver].size() == 0) {
				maxdepthnow = currentdepth;
				maxdepth[ver] = maxdepthnow;
			}

			else if (edge[ver].size() == init[ver]) {
				// debug(ver);
				ll childnum = edge[ver].size();
				priority_queue<ll> depthlist;
				priority_queue<ll> currentdepthlist;
				// debug(childnum);
				REP(i, edge[ver].size()) {
					depthlist.push(maxdepth[edge[ver][i]]);
				}
				ll totadd = 0;
				while (childnum > 0) {
					childnum--;
					ll q = depthlist.top();
					currentdepthlist.push(q + totadd);
					depthlist.pop();
					totadd++;
				}
				maxdepth[ver] = currentdepthlist.top();
				// vdebug(maxdepth);
			}
			FOR(i, init[ver], edge[ver].size()) {
				init[ver]++;
				if (!visited[edge[ver][i]]) {
					stack.push(edge[ver][i]);
					currentdepth++;
					maxdepthnow = -1;
					pop = false;
					break;
				}
			}

			if (pop) {
				stack.pop();
				currentdepth--;
				// maxdepth[ver] = maxdepthnow;
			}
		}
	}
};

int main()
{
	ll N;
	cin >> N;

	Tournament Tournament(N);
	mat edge(N, vec(0));

	ll p;
	REP(i, N - 1) {
		cin >> p;
		p--;
		Tournament.par[i + 1] = p;
		edge[p].pb(i + 1);
		// edge[i + 1].pb(p);
	}

	Tournament.ComptDepth(edge);

	// vdebug(Tournament.maxdepth);
	cout << Tournament.maxdepth[0] << endl;

	return 0;
}