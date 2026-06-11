#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define modulo 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60

class UF {
private:
	std::vector<int> parent;
	std::vector<int> level;
	std::vector<int> num_member; // 同じグループに属するメンバーの数
								 // 自身込み

public:
	// コンストラクタ　※注意※　0～nまでのn+1個を作る
	UF(int n) {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i); //
			level.push_back(1);  // 木の深さ
			num_member.push_back(1);
		}
	}
	// 木の根を求める
	int root(int x) {
		if (parent[x] == x)return x;
		else return parent[x] = root(parent[x]);
	}

	// 同じ集合に属するメンバーの数を求める
	int numOfmember(int x) {
		if (parent[x] == x) return num_member[x];
		else return num_member[x] = numOfmember(parent[x]);
	}

	// xとyの属する集合を合併
	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if (rx == ry) return; // 元々合併済みの場合
		if (level[rx] < level[ry]) {
			num_member[ry] = numOfmember(ry) + numOfmember(rx);
			parent[rx] = ry;
		}
		else {
			num_member[rx] = numOfmember(ry) + numOfmember(rx);
			parent[ry] = rx;
			if (level[rx] == level[ry]) level[rx]++;
		}
	}
	// xとyが同じ集合に属するか否か
	bool same(int x, int y) {
		return root(x) == root(y); // rootが同じなら同じ集合に含まれる
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K, L; cin >> N >> K >> L;

	UF roadConnect(N);
	UF trainConnect(N);

	for (int i = 0; i < K; i++) {
		int p, q; cin >> p >> q;
		roadConnect.unite(p, q);
	}

	for (int i = 0; i < L; i++) {
		int r, s; cin >> r >> s;
		trainConnect.unite(r, s);
	}

	map<P,int> M;
	for (int i = 1; i <= N; i++) M[P(roadConnect.root(i), trainConnect.root(i))]++;

	for (int i = 1; i <= N; i++) {
		cout << M[P(roadConnect.root(i), trainConnect.root(i))] << " ";
	}
	cout << endl;
	
	return 0;
}