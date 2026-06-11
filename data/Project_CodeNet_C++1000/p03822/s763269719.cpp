#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define mp make_pair
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const long long MXN = 3e5 + 1;
const long long MNN = 1e3 + 1;
const long long MOD = 998244353;
const long long INF = 1e18;
const long long OO = 1e15;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong n, x;
vector<int> q[MXN];
vector<int> v;

llong dfs(int x){
	vector<llong> v;
	for(int i = 0; i < q[x].size(); i++){
		v.pb(dfs(q[x][i]));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	llong mx = 0;
	for(int i = 0; i < v.size(); i++){
		mx = max(v[i] + i + 1, mx);
	}
	return mx;
}

int main(){
	ios;
	cin >> n;
	for(int i = 2; i <= n; i++){
		cin >> x;
		q[x].pb(i);
	}
	cout << dfs(1);
	return 0;
}
