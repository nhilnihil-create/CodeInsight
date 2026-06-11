#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>
#include<map>

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
using namespace std;

const LL MOD = 1000000007;// 10^9+7
const int INF = (1 << 30);

//名前の通り。　N個の独立した要素を併合するときに使用
class UnionFind {
public:
	vector<int>rank, parent;
	//初期化
	UnionFind(){}
	UnionFind(int size) {
		rank.resize(size, 0);
		parent.resize(size, 0);
		REP(i, size)parent[i] = i;
	}
	//木の根を求める
	int find(int x) {
		if (parent[x] == x)return x;
		else return parent[x] = find(parent[x]);
	}
	//xとyの属する集合を併合
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return;
		if (rank[x] < rank[y])
			parent[x] = y;
		else {
			parent[y] = x;
			if (rank[x] == rank[y])rank[x]++;
		}
	}
	//xとyが同じ集合に属するか否か
	bool same(int x, int y) {
		return (find(x) == find(y));
	}
	//parentの内容を出力
	void debug() {
		for (auto num : parent) {
			cout << num << " ";
		}
		cout << "more:" << endl;
		REP(i, parent.size()) {
			cout << find(i) << " ";

		}
		cout << endl << "more:" << endl;
		for (auto num : parent) {
			cout << num << " ";
		}
		cout << endl;
	}
};





//変数
int N, K, L;
UnionFind road, rail;





//サブ関数
//入力
void input()
{
	cin >> N >> K >> L;
	road = UnionFind(N);
	rail = UnionFind(N);

	int l, r;
	REP(i, K) {
		cin >> l >> r;
		l--; r--;
		road.unite(l, r);
	}

	REP(i, L) {
		cin >> l >> r;
		l--; r--;
		rail.unite(l, r);
	}
}


//計算
void calc()
{
	vector<pair<int, int>> group;//各都市の、所属している道路集合と鉄道集合の親ノードid
	REP(i, N) {
		group.push_back(make_pair(road.find(i), rail.find(i)));
	}

	map<pair<int, int>, int>mp; //引数：親ノードセット　　返り値：個数
	for (auto gp : group) {
		if (mp.find(gp) != mp.end()) {
			mp[gp]++;
		}
		else {
			mp[gp] = 1;
		}
	}

	for (auto gp : group) {
		cout << mp[gp] << " ";
	}
	cout << endl;
}


//出力
void output()
{

}


//デバッグ
void debug()
{
	int N;
	cin>>N;
}


//メイン関数
int main()
{
	input();
	calc();
	output();
	debug();
	
	return 0;
}
