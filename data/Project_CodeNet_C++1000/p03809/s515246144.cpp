#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<chrono>
#include<boost/multiprecision/cpp_int.hpp>
#define int int64_t
#define uint uint64_t
#define REP(i, a, b) for (int64_t i = (int64_t)(a); i < (int64_t)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define EACH(i, a) for (auto i: a)
#define ITR(x, a) for (auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define Min(x) *min_element(ALL(x))
#define Max(x) *max_element(ALL(x))
#define Unique(L) (L.erase(unique(ALL(L)), L.end()))
#define veccat(v1, v2) std::copy((v2).begin(),(v2).end(),std::back_inserter(v1)/*v1の後ろにv2を入れる*/)
#define intmax (std::numeric_limits<int64_t>::max() / 4)
using namespace std;
typedef boost::multiprecision::cpp_int bigint;
const double EPS = 1e-9;
const double PI = acos(-1.0);

int N;
vector<int>A;
vector<vector<int>>tree;
vector<int>depth;

int localmax(vector<int>v) {
	int maxv = 0;
	rep(i, v.size())maxv = max(maxv, v[i]);
	int sumv = 0;
	rep(i, v.size())sumv += v[i];
	return min(sumv-maxv, sumv / 2);
}

int solve(const int node) {
	if (tree[node].size() == 1) {

		if (depth[node] == 0) {//root is a leaf
			const int x = solve(tree[node][0]);
			if (x == -1) {
				return -1;
			}
			if (x == A[node])return 0;
			return -1;
		}

		//leaf
		return A[node];
	}

	int childsum = 0;
	vector<int>v;
	for (int x : tree[node])if (depth[x] > depth[node]) {
		const int y = solve(x);
		if (y == -1) {
			return -1;
		}
		if (y > 0)v.push_back(y);
		childsum += y;
	}
	const int count = localmax(v);
	if (!(childsum - count <= A[node] && A[node] <= childsum)) {
		return -1;
	}
	const int local = childsum - A[node];
	return A[node] - local;
}

signed main()
{
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);

	cin >> N;
	A = vector<int>(N);
	rep(i, N)cin >> A[i];
	tree = vector<vector<int>>(N);
	rep(i, N - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	depth = vector<int>(N, -1);
	stack<pair<int,int>>dfs;
	dfs.push(make_pair(0,0));
	while (!dfs.empty()) {
		auto x = dfs.top();
		dfs.pop();
		if (depth[x.first] != -1)continue;
		depth[x.first] = x.second;
		for (int y : tree[x.first]) {
			dfs.push(make_pair(y, x.second + 1));
		}
	}

	const int ans = solve(0);
	cout << (ans == 0 ? "YES" : "NO") << endl;

	return 0;
}