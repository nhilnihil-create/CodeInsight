#include <bits/stdc++.h>

using namespace std;

int makecombi(int i, int n, vector<int> &s, vector<vector<int>> &ss, int &counter) {

	if (i == n) {
		for (int j = 0; j < n; j++) {
//			cout << s[j];
			ss[counter][j] = s[j];
		}
//		cout << endl;
		counter++;
		return 0;
	}

	makecombi(i + 1, n, s, ss, counter);
	s[i] = 1;
	makecombi(i + 1, n, s, ss, counter);
	s[i] = 0;
	return 0;
}

int main() {

	int n, k;
	cin >> n >> k;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//01の組み合わせを作る
	//n：桁数
	//s：組み合わせの各桁
	//ss:組み合わせ結果の配列
	//counter:配列格納のためのカウンタ

	/*int n;
	cin >> n;*/

	vector<int> s(n, 0);
	vector<vector<int>> ss(pow(2, n), vector<int>(n, 0)); //組み合わせは2^n個ある
	int counter = 0;;

	makecombi(0, n, s, ss, counter);

//	cout << endl << endl;
	long long mincost = 100000000000;
	for (int i = 0; i < counter; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) {
			if (ss[i][j] == 1) { tmp++; }
//			cout << ss[i][j];
		}
		if (tmp == k) {
			long long maxh = 0;
			long long cost = 0;
			for (int j = 0; j < n; j++) {
				if (ss[i][j] == 1) {
					if (a[j] > maxh) {
						maxh = a[j];
					}
					else {
						cost = cost+maxh - a[j] + 1;
						maxh = maxh+1;
					}
				}
				else {
					maxh = max(maxh, a[j]);
				}
			}
			mincost = min(mincost, cost);
		}

//		cout << endl;
	}
	cout << mincost << endl;
	return 0;
}