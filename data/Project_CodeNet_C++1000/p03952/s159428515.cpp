#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
queue<int> que;
int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i < 2 * n; i++) {
		que.push(i);
	}
	if (x != 1 && x != 2 * n - 1) {
		cout << "Yes" << endl;
		int co = x - n;
		if (co < 0) {
			co += 2 * n - 1;
		}
		for (int i = 0; i < co; i++) {
			int y = que.front();
			que.pop();
			que.push(y);
		}
		for (int i = 0; i < 2 * n - 1; i++) {
			cout << que.front() << endl;
			que.pop();
		}
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
