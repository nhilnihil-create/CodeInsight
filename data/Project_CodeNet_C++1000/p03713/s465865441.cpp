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
long long m[4][3];
long long a[10][7];
long long ans[10];
int main(){
	long long h, w;
	cin >> h >> w;
	ans[0] = ((h + 2) / 3 - h / 3) * w;
	ans[1] = ((w + 2) / 3 - w / 3) * h;
	ans[2] = abs(h / 3 * w - ((h - h / 3)* ((w + 1) / 2)));
	ans[3] = abs((h + 2) / 3 * w - ((h - (h + 2)/ 3) * (w / 2)));
	ans[4]= abs(w / 3 * h - ((w - w / 3) * ((h + 1) / 2)));
	ans[5] = abs((w + 2) / 3 * h - ((w - (w + 2) / 3) * (h / 2)));
	long long ans1 = 10000000000007;
	for (int i = 0; i < 6; i++) {
		if (ans1 > ans[i]) {
			ans1 = ans[i];
		}
	}
	cout << ans1 << endl;
	return 0;
}