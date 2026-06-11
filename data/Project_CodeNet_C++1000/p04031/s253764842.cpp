#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int min_x = 0;
	for (int i = 0;i < n;i++) {
		min_x += a[i];
	}
	min_x /= n;
	int ansl, ansr;
	ansl = ansr = 0;
	for (int i = 0;i < n;i++) {
		ansl += (a[i] - min_x) * (a[i] - min_x);
		ansr += (a[i] - min_x - 1) * (a[i] - min_x - 1);
	}
	cout << min(ansl, ansr) << endl;
}