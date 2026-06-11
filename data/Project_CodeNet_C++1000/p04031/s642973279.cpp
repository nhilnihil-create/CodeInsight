#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<double> a(n);
	double summ=0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		summ += a[i];
	}
	summ /= n;
	int summm;
	summm = round(summ);

	int summmm=0;
	for (int i = 0; i < n; i++) {
		summmm += (a[i] - summm)*(a[i] - summm);
	}
	cout << summmm << endl;
}