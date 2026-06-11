#include<iostream>
#include<map>
using namespace std;

int dx[] = { -1,0,1,-1,0,1,-1,0,1 }, dy[] = { -1,-1,-1,0,0,0,1,1,1 };

int main() {
	int H, W, N; cin >> H >> W >> N;
	map<int, map<int, int>>mp; long long cnt[10] = {};
	cnt[0] = (long long)(H - 2) * (W - 2);
	for (int i = 0, a, b; i < N; i++) {
		cin >> a >> b;
		for (int j = 0; j < 9; j++)mp[a + dy[j]][b + dx[j]]++;
	}
	for (auto&& row : mp) {
		int y = row.first;
		if (y < 2 || H - 1 < y)continue;
		for (auto&& col : row.second) {
			int x = col.first;
			if (x < 2 || W - 1 < x)continue;
			cnt[col.second]++; cnt[0]--;
		}
	}
	for (int i = 0; i < 10; i++)cout << cnt[i] << endl;

	return 0;
}