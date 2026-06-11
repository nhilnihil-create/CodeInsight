#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int d[110][110];
int dist[110][110];
void warshall_floyd(int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
int solve(int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] == mod) continue;	
			if (d[i][j] != dist[i][j]) ans++;
		}
	}
	return ans / 2;
}
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				d[i][j] = mod;
				dist[i][j] = mod;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		d[a][b] = c;
		d[b][a] = c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	warshall_floyd(N);
	cout << solve(N) << endl;
}
