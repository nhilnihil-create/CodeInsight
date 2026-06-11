#include <iostream>
#include <vector>

using namespace std;

int N, M, Q, a[100005], b[100005], v[100005],c[100005],d[100005];

vector<int> Adj[100005];
int q[100005];
int dis[100005];

/*int D_base;
int query_num;

void INIT(int K, int D) {

	dis[K] = D;

	if ((q[K] > 0) && ( D_base - dis[K] <= d[q[K]])) {
		if (query_num < q[K]) { query_num = q[K];  }
	}

	if (D > 0) {
		for (int u = 0; u < (int)Adj[K].size(); u++) {
			int H = Adj[K][u];
			if (dis[H] < D) { INIT(H, D - 1); }
		}
	}

	dis[K] = 0;
}
*/

int check[100005];
int color[100005];

/*void PAINT(int v, int d, int c) {
	
	check[v] = d;
	
	if (color[v] == 0) { color[v] = c; }

	if (d > 0) {
		for (int u = 0; u < (int)Adj[v].size(); u++) {
			int w = Adj[v][u];
			if (check[w] < d) { PAINT(w, d - 1, c); }
			//PAINT(w, d - 1, c);
		}

	}
	check[v] = 0;
}*/

int memo[100005][15];

void FUNC(int V, int D, int C) {
	//cout << "V= " << V << " D= " << D <<" C= " <<C<< endl;

	if (memo[V][D] > 0) { return; }
	memo[V][D] = C;

	if (D>0) { FUNC(V,D - 1,C); }

	for (int u = 0; u < (int)Adj[V].size(); u++) {
		int H = Adj[V][u];
		if (D>0) { FUNC(H, D - 1, C); }
	}
}

int main(void) {

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a[i] >> b[i];
		Adj[a[i]].push_back(b[i]);
		Adj[b[i]].push_back(a[i]);
	}

	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> v[i] >> d[i] >> c[i];
		q[v[i]] = i;
	}

	for (int i = Q; i >= 1; i--) {
		FUNC(v[i], d[i], c[i]);
	}


/*
	for (int i = 1; i <= N; i++) {
		query_num = -1;
		D_base = 10;
		INIT(i, 10);
		//cout << "query_num= " << query_num << endl;
		if (query_num == -1) { cout << 0 << endl; }
		else { cout << c[query_num] << endl; }
	}*/

	/*for (int i = Q; i >=1; i--) {
		PAINT(v[i], d[i], c[i]);
	}

	for (int i = 1; i <= N; i++) {
		cout << color[i] << endl;
	}
	*/

	for (int i = 1; i <= N; i++) {
		cout << memo[i][0] << endl;
	}
	
	//system("pause");
	return 0;
}