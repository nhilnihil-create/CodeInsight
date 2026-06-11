//構成の方針まではすぐだけど、正確に詰めるのは難しい。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
int fc[200002];	//fc[i] = sの前からi文字を取り除いたとき、(abc…z)のアナグラムをn個連結した文字列を見つけられたとする。nの最大値をfc[i]とおく。ただし、fc[|s|+1] = -1とおく。
vector<int> posList[26];

void calcFc() {
	bool used[26] = {false}; int uCnt = 0, findCnt = 0;
	int i, j;
	
	fc[n + 1] = -1;
	for (i = n - 1; i >= 0; i--) {
		if (!used[s[i] - 'a']) {
			used[s[i] - 'a'] = true;
			uCnt++;
		}
		if (uCnt == 26) {
			findCnt++;
			uCnt = 0;
			for (j = 0; j < 26; j++) used[j] = false;
		}
		fc[i] = findCnt;
	}
}

int main() {
	int i, j;
	
	cin >> s; n = s.length();
	calcFc();
	
	for (i = 0; i < n; i++) {
		posList[s[i] - 'a'].push_back(i);
	}
	for (i = 0; i < 26; i++) {
		posList[i].push_back(n);
	}
	
	string ans;
	int lastPos = -1;
	for (i = 0; i < fc[0] + 1; i++) {
		for (j = 0; j < 26; j++) {
			int id = upper_bound(posList[j].begin(), posList[j].end(), lastPos) - posList[j].begin();
			int pos = posList[j][id];
			if (fc[pos + 1] == fc[0] - i - 1) {
				//文字'a' + jを答えに追加する
				ans += (char)('a' + j);
				lastPos = pos;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}