#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll, ll>;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using Graph = VV;
int Inf = (1 << 30);
ll inf = (1LL << 60);
const int MOD = 1e9 + 7;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int i, j;
	bool flag = false;
	for (i = 0; i <= m; i++) { // i個おす
		for (j = 0; j <= n; j++) { // j個おす
			int tmp = 0;
			tmp += (i * n);
			tmp += (j * m);
			tmp -= 2 * (i * j);
			 // cout << tmp << endl;
			if (tmp == k) flag++;
		}
	}
	if (flag) cout << "Yes";
	else cout << "No";
	return 0;
}