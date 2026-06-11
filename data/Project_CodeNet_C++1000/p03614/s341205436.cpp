#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	vector<int> v;
	for (int i = 1; i <= n; i++) {//
		if (a[i] == i) {
			v.push_back(i);
		}
	}
	int tt = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i!=0 && v[i] - v[i - 1] == 1)++tt;
		else {
			cnt += (tt + 1) / 2;
			tt = 1;
		}
	}
	if (tt) {
		cnt += (tt + 1) / 2;
	}
	printf("%d", cnt);
}