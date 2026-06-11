#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
	double a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	
	double X, Y;
	double mx = -1.0;

	vector<double> x;
	vector<double> y;

	for (int i = 0; i <= f; i++) {
		for (int j = 0; j <= f; j++) {
			X = 100.0 * a * i + 100.0 * b * j;
			Y = c * i + d * j;
			if (X <= f) {
				x.push_back(X);
			}
			if (Y <= f) {
				y.push_back(Y);
			}
		}
	}

	double p = e / 100.0;
	
	double ans1;
	double ans2;
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			double t = x[i] + y[j];
			if (t <=  f) {
				//double s = y[j] / x[i];
				double s =  y[j] / x[i];
				if (s <= p) {
					if (mx <= s) {
						mx = s;
						ans1 = x[i]+y[j];
						ans2 = y[j];
					}
				}
			}
		}
	}

	cout << ans1 <<" "<< ans2 << endl;

	return 0;
}