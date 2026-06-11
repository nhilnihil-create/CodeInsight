#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF_LL (ll)1e18
#define INF (int)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
using ll = long long;
using PII = pair<int, int>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

class Union_find{
private:
	vector<int> par;
	vector<int> rank;
	int n;

public:
	Union_find(int a){
		n = a;
		for(int i = 0;i < n;i++){
			par.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};

const ll mod = 1e9+7;

int main(void){
	int W, H;
	ll p[114514], q[114514];
	cin >> W >> H;
	ll res = 0;
	REP(i, W){
		cin >> p[i];
		res += p[i];
	}
	REP(i, H){
		cin >> q[i];
		res += q[i];
	}
	sort(p, p+W);
	sort(q, q+H);
	REP(i, W){
		int in = lower_bound(q, q+H, p[i])-q;
		res += (H-in)*p[i];
	}
	REP(i, H){
		int in = upper_bound(p, p+W, q[i])-p;
		res += (W-in)*q[i];
	}
	cout << res << endl;
}
