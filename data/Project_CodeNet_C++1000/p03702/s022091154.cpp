#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;


int main() {
	complex<long double>cmpmp;
	const long long int mod = 1000000007;
	map<long long int, long long int>mp;
	//cout << fixed << setprecision(10);
	long long int N, A, B, h[200000],left=0,right=1000000000,bomb;
	cin >> N >> A>>B;
	for (int i = 0; i < N; i++) {
		cin >> h[i];

	}
	while (right - left != 1) {
		long long int mid = (left + right) / 2;
		bomb = mid;
		for (int i = 0; i < N; i++) {
			bomb -= max(( h[i] - mid * B +A-B- 1) / (A - B),0LL);
		}
		if (bomb >= 0) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	cout << right << endl;
}