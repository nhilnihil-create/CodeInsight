#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int h, w, n; cin >> h >> w >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];		
	
	vector<int> st(h * w);
	vector<vector<int>> ans(h, vector<int>(w));

	int cnt = 1;
	int k = 0;
	int hw = h * w;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			st[k] = cnt;
			k++;
		}
		cnt++;
	}

	cnt = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			ans[i][j] = st[cnt];
			cnt++;
		}
	}

	for (int i = 0; i < h; i++) {
		if (i % 2 != 0 ) {
			reverse(ans[i].begin(), ans[i].end());
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}