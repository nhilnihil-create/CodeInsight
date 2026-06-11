#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

vector<tuple<int, int, int>> E;
int dist[300][300], D[300][300];
bool used[300][300];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N;
	long long ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		cin >> dist[i][j];
		D[i][j] = dist[i][j];
		E.push_back(make_tuple(D[i][j], i, j));
	}
	for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (dist[i][j] != D[i][j]) {
		cout << "-1\n";
		return 0;
	}
	sort(E.begin(), E.end());
	for (auto e : E) {
		int w, u, v;
		tie(w, u, v) = e;
		for (int i = 0; i < N; i++) {
			if (used[u][i] && used[i][v] && D[u][i] + D[i][v] == D[u][v]) {
				w = 0;
				break;
			}
		}
		used[u][v] = true;
		ans += w;
	}
	cout << ans / 2 << '\n';
	return 0;
}