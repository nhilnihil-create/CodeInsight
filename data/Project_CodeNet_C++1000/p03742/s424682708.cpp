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
	long long int N,M, W,w[200],v[200],dp[105][105][305];
	cin >> N >> M;
	if (abs(N - M) >= 2) {
		cout << "Alice" << endl;
	}
	else {
		cout << "Brown" << endl;
	}
}