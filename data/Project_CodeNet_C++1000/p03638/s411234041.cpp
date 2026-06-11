#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, i, j, k, nn, x, y, xx, yy, p, ct;
	int v[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
	cin >> n >> m >> nn;
	vector<int> a(nn);
	for (i = 0; i < nn; i++) cin >> a[i];

	vector<vector<int>> ans(n, vector<int>(m, -1));
	ct = 0;
	for (i = 0; i < nn; i++) {
		for (j = 0; j < a[i]; j++) {
			if (ct == 0) {
				x = 0; y = 0; p = 0;
			}
			else {
				while(1) {
					xx = x + v[p][0]; yy = y + v[p][1];
					if ((xx >= 0) && (xx < n) && (yy >= 0) && (yy < m) && (ans[xx][yy] == -1)) break;
					p = (p + 1) % 4;
				}
				x = xx; y = yy;
			}
			ct++;
			ans[x][y] = i + 1;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) cout << ans[i][j] << " ";
		cout << "\n";
	}

	return 0;
}

