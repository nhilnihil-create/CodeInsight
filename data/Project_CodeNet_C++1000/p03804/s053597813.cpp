#include<bits/stdc++.h>
#include<unordered_map>	
#include<unordered_set>
#define pb emplace_back
#define rt(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(a) a.begin(),a.end()
#define endl '\n'
#define space " "
typedef long long ll;
typedef unsigned long long ull;
const int N = 10 + 1e5;
const int mod = 1e9 + 7;
/*

███╗   ███╗███████╗███╗   ███╗███████╗    ██╗      ██████╗ ██████╗ ██████╗
████╗ ████║██╔════╝████╗ ████║██╔════╝    ██║     ██╔═══██╗██╔══██╗██╔══██╗
██╔████╔██║█████╗  ██╔████╔██║█████╗      ██║     ██║   ██║██████╔╝██║  ██║
██║╚██╔╝██║██╔══╝  ██║╚██╔╝██║██╔══╝      ██║     ██║   ██║██╔══██╗██║  ██║
██║ ╚═╝ ██║███████╗██║ ╚═╝ ██║███████╗    ███████╗╚██████╔╝██║  ██║██████╔╝
╚═╝     ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝    ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝

*/

using namespace std;
void Ferrari() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
char img[55][55];
char temp[55][55];
char ans[55][55];
int n, m;
bool check() {
	bool ok = 1;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			if (ans[i][j] != temp[i][j])
			{
				ok = 0; break;
			}
	return ok;
}
int main() {
	Ferrari();
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> img[i][j];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			cin >> temp[i][j];
	bool ok = 0;
	for (int i = 0; i <= n - m; ++i) {
		for (int a = i; a < i + m; ++a)
			for (int j = 0; j < m; ++j)
				ans[a][j] = img[a][j];
		if (check()) ok = 1;
		for (int c = m; c < n; ++c) {
			for (int a = 1; a < m; ++a)
				for (int j = 0; j < m; ++j)
					ans[j][a - 1] = ans[j][a];
			for (int a = 0; a < m; ++a)
				ans[a][m - 1] = img[i + a][c];
			if (check()) ok = 1;
		}
	}
	cout << (ok ? "Yes" : "No");
	return 0;
}





/* stuff you should look for
	* keepin sharp mind.
	* int overflow, array bounds.
	* special cases (n=1?), set tle , make sure you understand the proble correctly.
	* don`t stuck in a problem.
	* test the idea on samples.
	*/