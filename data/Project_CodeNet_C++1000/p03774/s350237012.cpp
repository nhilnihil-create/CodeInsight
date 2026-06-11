#include<bits/stdc++.h>
using namespace std;
int dist(int a, int b, int c, int d) {
	return abs(a-c)+abs(b-d);
}
int main () {
	long long n, m;
	cin >> n >> m;
	int a[100];
	int b[100];
	int c[100];
	int d[100];
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i=0; i<m; i++) {
		cin >> c[i] >> d[i];
	}
	int luu;
	for (int i=0; i<n; i++) {
		int mi = 1e9;
		for (int j=0; j<m; j++) {
			int x = dist(a[i], b[i], c[j], d[j]);
			if (x<mi) {
				mi = x;
				luu = j;
			}
		}
		cout << luu+1 << "\n";
	}
}