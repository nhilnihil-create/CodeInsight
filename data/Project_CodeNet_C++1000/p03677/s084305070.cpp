#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n, m;
vector<int> pos[100000 + 100];
ll a[100000 + 100];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	
	ll ans = 0, cur = 0;
	int shortcut = 0;
	for (int i = 1; i < n; i++) {
		if ((m + a[i] - a[i - 1]) % m >= ((m + a[i] - 1) % m) + 1) {
			if (a[i] == 1) {
				//x+1で外れるとき。
				cur += (m + a[i] - a[i - 1]) % m;
			}else shortcut++, cur += ((m + a[i] - 1) % m) + 1;
			ans += ((m + a[i] - 1) % m) + 1;
		}
		else {
			ans += (m + a[i] - a[i - 1]) % m;
			cur += (m + a[i] - a[i - 1]) % m;
		}
	}
	
	for (int x = 2; x <= m; x++) {
		cur -= shortcut;
		ans = min(ans, cur);
		//このxからショートカットをするとかかる時間がそのまま以下になるもの
		for (int i = 0; i < pos[x - 1].size(); i++) {
			int idx = pos[x - 1][i];
			if (idx != n - 1) {
				shortcut++;
			}
		}

		//このxから、ショートカットをするより、普通にやったほうが同じか以上になるもの
		for (int i = 0; i < pos[x].size(); i++) {
			int idx = pos[x][i];
			if (idx != 0) {
				shortcut--;
				cur += (m + a[idx] - a[idx - 1]) % m - 1;
			}
		}
	}

	cout << ans << endl;
	return 0;
}