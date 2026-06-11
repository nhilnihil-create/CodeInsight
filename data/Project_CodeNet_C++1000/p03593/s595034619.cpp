#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int main() {
	int h, w;
	cin >> h >> w;
	int cnt[26] = {};
	for (int i = 0; i < h * w; i++) {
		char c;
		cin >> c;
		cnt[c - 'a']++;
	}
	bool ok = true;
	for (int i = 0; i < (h / 2) * (w / 2); i++) {
		for (int j = 0; j < 26; j++) {
			if (cnt[j] >= 4) {
				cnt[j] -= 4;
				break;
			}
			if (j == 25) {
				ok = false;
				i = h * w;
			}
		}
	}
	if (h % 2 == 1) {
		for (int i = 0; i < w / 2; i++) {
			for (int j = 0; j < 26; j++) {
				if (cnt[j] >= 2) {
					cnt[j] -= 2;
					break;
				}
				if (j == 25) {
					ok = false;
					i = w;
				}
			}
		}
	}
	if (w % 2 == 1) {
		for (int i = 0; i < h / 2; i++) {
			for (int j = 0; j < 26; j++) {
				if (cnt[j] >= 2) {
					cnt[j] -= 2;
					break;
				}
				if (j == 25) {
					ok = false;
					i = h;
				}
			}
		}
	}
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}