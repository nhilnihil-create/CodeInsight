#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#define LL long long
#define PP std::pair<int,int>
#define TT std::tuple<int,int,int>
std::vector<TT> res;
int rank[200010];
int par[200010];
int ans[200010];
int N, K, L;
void init(int n) {
	for (int i = 1; i <= N; i++) {
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x) {
	if (par[x] == x)return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rank[x] < rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank[x] == rank[y])rank[x]++;
	}
	return;
}

int memo[200010];
bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	std::cin >> N >> K >> L;
	init(N);
	for (int i = 0; i < K; i++) {
		int a, b;
		std::cin >> a >> b;
		unite(a, b);
	}
	for (int i = 1; i <= N; i++) {
		memo[i] = find(i);
	}
	init(N);
	for (int i = 1; i <= L; i++) {
		int a, b;
		std::cin >> a >> b;
		unite(a, b);
	}
	for (int i = 1; i <= N; i++) {
		res.push_back(TT{ memo[i],find(i),i });
	}
	std::sort(res.begin(), res.end());
	std::vector<int> S;
	int a, b, c;
	TT t = res[0];
	std::tie(a, b, c) = t;
	S.push_back(c);
	int befa, befb;
	befa = a;
	befb = b;
	for (int i = 1; i < (int)res.size(); i++) {
		t = res[i];
		std::tie(a, b, c) = t;
		if (a == befa&&b == befb) {
			S.push_back(c);
		}
		else {
			for (auto u : S) {
				ans[u] += S.size();
			}
			S.clear();
			befa = a;
			befb = b;
			S.push_back(c);
		}
	}
	for (auto u : S) {
		ans[u] += S.size();
	}
	for (int i = 1; i <= N; i++) {
		std::cout << ans[i];
		if (i != N)std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}