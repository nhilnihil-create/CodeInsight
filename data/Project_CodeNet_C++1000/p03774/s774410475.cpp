#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int N,M;
	cin >> N>>M;
	vector<int> a(N),b(N),c(M),d(M);
	for (int i = 0; i < N; i++) {
		cin >> a[i]>>b[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> c[i] >> d[i];
	}
	vector<int> ans(N);
	for (int i = 0; i < N; i++) {
		int min_dis = 1000000000;
		for (int j = 0; j < M; j++) {
			if (min_dis > abs(a[i] - c[j]) + abs(b[i] - d[j])) {
				min_dis = abs(a[i] - c[j]) + abs(b[i] - d[j]);
				ans[i] = j+1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i]<<endl;
	}
}