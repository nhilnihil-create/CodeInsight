#include <iostream>
#include <vector>

using namespace std;

#define M 1000000007

int main() {

	long long int n, m;
	cin >> n >> m;

	vector<long long int> x(n);
	vector<long long int> y(m);

	for (long long int i = 0; i < n; i++) {
		cin >> x[i];
	}

	for (long long int i = 0; i < m; i++) {
		cin >> y[i];
	}

	long long int xx, yy;
	xx = yy = 0;

	for (long long int i = 0; i < n; i++) {
		xx -= x[i] * (n - 1 - i);
		xx += x[i] * i;
		xx %= M;
	}

	for (long long int i = 0; i < m; i++) {
		yy -= y[i] * (m - 1 - i);
		yy += y[i] * i;
		yy %= M;
	}

	cout << (xx*yy) % M << endl;

	return 0;
}