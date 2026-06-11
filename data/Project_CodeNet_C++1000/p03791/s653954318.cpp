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

#define INF_LL 1e18
#define INF 1e9

#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()

using namespace std;

using ll = long long;
using PII = pair<int, int>;

template<typename T>
void chmax(T &a, T &b){
	a = max(a, b);
}

template<typename T>
void chmin(T &a, T &b){
	a = min(a, b);
}

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
	int N;
	int x[114514];
	stack<int> s;
	ll res = 1;
	cin >> N;
	REP(i, N){
		cin >> x[i];
	}
	REP(i, N){
		s.push(x[i]);
		if(x[i] < 2*s.size()-1){
			res = (res*s.size())%mod;
			s.pop();
		}
	}
	REP(i, s.size()){
		res = (res*(i+1))%mod;
	}
	cout << res << endl;
}
