//1時間経過しました（大嘘）。嘘解法をお伝えします。
//貪欲に「Mの倍数」ペアを作って, 残った数であれする。
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

int n, m;
int x[100000];
int cnt[100001];		//mod Mして値をカウント
int used[100001];		//mod Mして値をカウント -> Mの倍数ペアを作る -> いくつ使ったか？

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		cnt[x[i] % m]++;
	}
}

//usedを使って, 同じ数で作る
int unko() {
	typedef pair<int, int> P;
	
	static int k_cnt[100000] = {0};	//k_cnt[i] = Mで割ってi余る要素のうち, 奇数個のものの個数
	map<int, int> m_cnt;
	
	for (int i = 0; i < n; i++) {
		if (m_cnt.find(x[i]) == m_cnt.end()) {
			m_cnt[x[i]] = 0;
		}
		m_cnt[x[i]]++;
	}
	
	for (map<int, int>::iterator it = m_cnt.begin(); it != m_cnt.end(); it++) {
		int val = (*it).first;
		int cnt = (*it).second;
		if (cnt % 2 == 1) k_cnt[val % m]++;
	}
	
	static int loss[100000] = {0};		//loss[i] = 奇数で残ってしまう整数の個数
	for (int i = 0; i < m; i++) {
		if (k_cnt[i] >= used[i]) {
			loss[i] = k_cnt[i] - used[i];
		}
		else {
			loss[i] = (used[i] - k_cnt[i]) % 2;
		}
	}
	
	int ret = 0;
	for (int i = 0; i < m; i++) {
		ret += (cnt[i] - loss[i]) / 2;
	}
	return ret;
}

signed main() {
	input();
	
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int p = m - i;
		if (i == 0) p = 0;
		
		if (i == 0 || i == p) {
			int plus = cnt[i] / 2;
			ans += plus;
			cnt[i] -= 2 * plus;
			used[i] += 2 * plus;
		}
		else {
			int plus = min(cnt[i], cnt[p]);
			ans += plus;
			cnt[i] -= plus;
			cnt[p] -= plus;
			used[i] += plus;
			used[p] += plus;
		}
	}
	
	ans += unko();
	
	cout << ans << endl;
	return 0;
}