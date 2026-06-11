#define _USE_MATH_DEFINES 
#include <iomanip> 
#include <cmath>  
#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl

const int N_MAX = 2 * 100000;

struct ABpair {
	int a, b;
	bool operator<(const ABpair& right) const {
		return a == right.a ? b < right.b : a < right.a;
	}
};

int N, K, L, counter;
int groups[2][N_MAX + 10];//グループ覚える
map<ABpair,int> group_pair_count;//ペアを数える
bool invited[2][N_MAX + 10];
vector<int> nodes[2][N_MAX + 10];
bool c_flag;

void DFS(int g, int n, int c) {//i:道の種類, n:現在みている点, c:グループの種類
	if (invited[g][n]) return;
	c_flag = true;
	invited[g][n] = true;
	groups[g][n] = c;
	repi(i, 0, nodes[g][n].size()) {
		DFS(g, nodes[g][n][i], c);
	}
	return;
}

int main() {
	cin >> N >> K >> L;
	repi(i, 0, K) {
		int p, q;
		cin >> p >> q;
		nodes[0][p].push_back(q);
		nodes[0][q].push_back(p);
	}
	repi(i, 0, L) {
		int r, s;
		cin >> r >> s;
		nodes[1][r].push_back(s);
		nodes[1][s].push_back(r);
	}

	repi(i, 0, 2) {
		repi(j, 1, N + 1) {
			DFS(i, j, counter);
			if (c_flag) {
				counter++;
				c_flag = false;
			}
		}
	}

	repi(i, 1, N + 1) {
		ABpair abp;
		abp.a = groups[0][i];
		abp.b = groups[1][i];
		group_pair_count[abp]++;
	}

	repi(i, 1, N + 1) {
		ABpair abp;
		abp.a = groups[0][i];
		abp.b = groups[1][i];
		wr(group_pair_count[abp]);
		if (i == N) cout << endl;
		else wr(" ");
	}

	return 0;
}