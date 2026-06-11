#include<iostream>
#include<algorithm>
#define MAX 100005
using namespace std;
int a[MAX],minn[MAX], maxx[MAX], maxdif,ans;
int main() {
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	minn[1] = a[1];
	for (int i = 2; i <= n; i++) {
		minn[i] = min(minn[i-1], a[i]);
	}
	maxx[1] = a[n];
	for (int i = n; i >= 1; i--) {
		maxx[i] = max(maxx[i + 1], a[i]);
	}
	for (int i = 1; i <= n; i++) {
		maxdif = max(maxdif,maxx[i] - minn[i]);
	}
	int ma=-1,mi = -1;
	for (int i = 1; i <= n; i++) {
		if (maxx[i]-minn[i] == maxdif && maxx[i] != ma &&
			minn[i] != mi) {
			ma = maxx[i];
			mi = minn[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}