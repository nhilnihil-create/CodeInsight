#include<iostream>
using namespace std;
int a[1000];
int cnt[1000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
	int mx = 0, mn = 100000;
	for (int i = 0; i < n; i++) mn = min(mn, a[i]), mx = max(mx, a[i]);
	if (mx % 2 == 0)
	{
		if (cnt[mn] != 1) {
			cout << "Impossible";
			return 0;
		}
		for (int i = mx; i > mn; i--) if (cnt[i] < 2) {
			cout << "Impossible";
			return 0;
		}
		cout << "Possible";
		return 0;
	}
	else
	{
		if (cnt[mn] != 2) {
			cout << "Impossible";
			return 0;
		}
		for (int i = mx; i > mn; i--) if (cnt[i] < 2) {
			cout << "Impossible";
			return 0;
		}
		cout << "Possible";
		return 0;
	}
}