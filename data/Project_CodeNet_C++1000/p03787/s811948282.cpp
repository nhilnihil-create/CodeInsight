#include<bits/stdc++.h>
using namespace std;

long long N, M;
vector<long long> tree[100005];

// 素集合データ構造
struct UnionFind
{
  // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
  vector<int> par;
  // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
	  // 最初は全てのデータiがグループiに存在するものとして初期化
	  for(int i = 0; i < n; i++){
		  par[i] = i;
	  }
  }

  // データxが属する木の根を得る
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
  }

  // 2つのデータx, yが属する木をマージする
  void unite(int x, int y) {
    // データの根ノードを得る
    x = find(x);
    y = find(y);

    // 既に同じ木に属しているならマージしない
    if (x == y) return;

    // xの木がyの木より大きくなるようにする
    if (sizes[x] < sizes[y]) swap(x, y);

    // xがyの親になるように連結する
    par[y] = x;
    sizes[x] += sizes[y];
    // sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
  }

  // 2つのデータx, yが属する木が同じならtrueを返す
  bool same(int x, int y) {
    return find(x) == find(y);
  }

  // データxが含まれる木の大きさを返す
  int size(int x) {
    return sizes[find(x)];
  }
};

long long colarr[100005];

bool nibuhelp(long long pa, long long idx, long long col){
	if(colarr[idx] != 0 && colarr[idx] != col){
		return false;
	}
	if(colarr[idx] != 0){
		return true;
	}
	colarr[idx] = col;
	for(long long i = 0; i < tree[idx].size(); i++){
		if(tree[idx][i] == pa){
			continue;
		}
		if(nibuhelp(idx, tree[idx][i], -1 * col) == false){
			return false;
		}
	}
	return true;
}


bool nibu(long long idx){
	return nibuhelp(-1, idx, 1);
}

int main(){
	cin >> N >> M;
	UnionFind uf(N);
	for(long long i = 0; i < M; i++){
		long long u, v;
		cin >> u >> v;
		u--;v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
		uf.unite(u, v);
	}

	set<long long> single;
	for(long long i = 0; i < N; i++){
		if(uf.size(i) == 1){
			single.insert(i);
		}
	}

	long long nibunum = 0;
	long long nonnibunum = 0;

	set<long long> done;
	for(long long i = 0; i < N; i++){
		if(single.count(i) != 0){
			continue;
		}
		if(done.count(uf.find(i)) != 0){
			continue;
		}

		done.insert(uf.find(i));
		if(nibu(i) == true){
			nibunum++;
		}else{
			nonnibunum++;
		}
	}
	long long ans = 0;
	//single vs single
	//single vs nibu
	//single vs nonnibu
	ans += single.size() * N;

	//nibu vs single
	//nonnibu vs single
	//single vs single
	ans += N * single.size();

	//- single vs single
	ans -= single.size() * single.size();

	//nibu vs nibu
	ans += nibunum * nibunum * 2;
	//nibu vs nonnibu
	ans += nibunum * nonnibunum;
	//nonnibu vs nibu
	ans += nonnibunum * nibunum;
	//nonnibu vs nonnibu
	ans += nonnibunum * nonnibunum;

	cout << ans << endl;
}
