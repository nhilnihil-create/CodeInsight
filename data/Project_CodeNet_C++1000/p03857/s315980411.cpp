#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

struct UnionFind{
    vector<int> parent, rank;
    UnionFind(int n){ parent = vector<int>(n, -1); rank = vector<int>(n, 0); }
    int find(int x){
        if(parent[x] == -1) return x;
        else return (parent[x] = find(parent[x]));
    }
    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y])
            parent[x] = y;
        else
            parent[y] = x;
        if(rank[x] == rank[y])
            ++rank[x];
        return true;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

signed main(){
	int N, K, L;
	cin >> N >> K >> L;
	UnionFind uf1(N), uf2(N);
	for(int i = 0; i < K; ++i) {
		int p, q;
		cin >> p >> q;
		uf1.unite(p - 1, q - 1);
	}
	for(int i = 0; i < L; ++i) {
		int r, s;
		cin >> r >> s;
		uf2.unite(r - 1, s - 1);
	}
	map<int, map<int,int>> mp;
	for(int i = 0; i < N; ++i) {
		mp[uf1.find(i)][uf2.find(i)]++;
	}
	for(int i = 0; i < N; ++i) {
		cout << mp[uf1.find(i)][uf2.find(i)] << (i == N - 1 ? "\n": " ");
	}
	return 0;
}
