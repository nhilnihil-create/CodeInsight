#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector< vector<int> > G;

void dfs(int cur, int par, vector<int>& col, bool& flag) {
	for (int nex : G[cur]) {
		if (nex == par) continue;
		if (col[nex] != -1) {
			if (col[nex] == col[cur]) flag = false;
			continue;
		}
		col[nex] = !col[cur];
		dfs(nex, cur, col, flag);
	}
}

struct Union_Find {
    //各要素が属する集合の代表(根)を管理する
    //もし、要素xが根であればdata[x]は負の値を取り、-data[x]はxが属する集合の大きさに等しい
    vector<int> data;
    
    Union_Find(int size) : data(size, -1) {}
    bool Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        bool is_union = (x != y);
        if (is_union) {
            if (data[x] > data[y]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return is_union;
    }
    int Find(int x) {
        if (data[x] < 0) { //要素xが根である
            return x;
        } else {
            data[x] = Find(data[x]); //data[x]がxの属する集合の根でない場合、根になるよう更新される
            return data[x];
        }
    }
    bool same(int x, int y) {
        return Find(x) == Find(y);
    }
    int size(int x) {
        return -data[Find(x)];
    }
};


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> u(m), v(m);
	Union_Find uf(n);
	G.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
		u[i]--;
		v[i]--;
		uf.Union(u[i], v[i]);
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}

	int cnt1 = 0, cnt2 = n;
	for (int i = 0; i < n; i++) {
		if (uf.Find(i) == i) {
			if (uf.size(i) > 1) cnt1++;
			else cnt2--;
		}
	}

	int cnt3 = cnt1;
	for (int i = 0; i < n; i++) {
		if (uf.Find(i) != i || uf.size(i) == 1) continue;
		bool flag = true;
		vector<int> col(n, -1);
		col[i] = 0;
		dfs(i, -1, col, flag);
		cnt3 -= !flag;
	}

	cout << (ll)n * n - (ll)cnt2 * cnt2 + (ll)cnt1 * cnt1 + (ll)cnt3 * cnt3 << endl;
	return 0;
}
