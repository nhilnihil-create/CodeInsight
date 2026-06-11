#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "bitset"

using namespace std;

//const long long int MOD = 998244353;
const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<int>>edge(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	long long int alone = 0;
	long long int two = 0;
	long long int other = 0;
	vector<int>used(N + 1);
	vector<int>dis(N + 1, MOD);
	for (int i = 1; i <= N; i++) {
		if (used[i])continue;
	//	cout << i << endl;
		if (edge[i].empty()) {
			alone++;
			used[i] = 1;
			continue;
		}
		dis[i] = 0;
		queue<int>Q;
		Q.push(i);
		bool flag = true;
		while (!Q.empty()) {
			int cn = Q.front();
			used[cn] = 1;
			Q.pop();
			for (auto j : edge[cn]) {
				if (dis[j] == MOD) {
					dis[j] = dis[cn] + 1;
					Q.push(j);
				}
				else {
					if (dis[j] % 2 == dis[cn] % 2) {
						flag = false;
					}
					if (dis[j] > dis[cn] + 1) {
						dis[j] = dis[cn] + 1;
						Q.push(j);
					}
				}
			}
		}
		if (flag)two++;
		else other++;
	}
	//cout << alone << " " << two << " " << other << endl;
	long long int ans = 0;
	ans += alone * alone;
	ans += alone * (N - alone) * 2;
	ans += other * other;
	ans += other * two * 2;
	ans += two * two * 2;
	cout << ans << endl;
	return 0;
}
