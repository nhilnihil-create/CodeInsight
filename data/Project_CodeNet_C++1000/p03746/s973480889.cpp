#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100009], ans;
bool vs[100009];

void dfs(int n)
{
	vs[n] = true; ans.push_back(n);
	for (int i = 0; i < v[n].size(); i++)
		if (!vs[v[n][i]]) {
			dfs(v[n][i]);
			return;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	int c = 0; vs[1] = true;
	for (int i = 0; i < v[1].size(); i++) {
		if (!vs[v[1][i]]) {
			dfs(v[1][i]);
			c++;
			if (c == 1) {
				reverse(ans.begin(), ans.end()); ans.push_back(1);
			}
		}
		if (c >= 2) break;
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}