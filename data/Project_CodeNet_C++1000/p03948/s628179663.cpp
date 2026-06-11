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
	long long int n,keymi=0,keyma=0, t, a[200050],mi=999999999999,ma=-1,micou=0,macou=0,sa=0,sacou=0,res=0;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >=1; i--) {
		
		if (ma < a[i]) {
			ma = a[i];
			mi = a[i];
			res += min(keyma, keymi);
			keyma = 0;
			keymi = 0;
		}
		if (mi > a[i]) {
			mi = a[i];
		}
		if (sa < ma - a[i]) {
			res = 0;
			sa = ma - a[i];
		}
		if (ma == a[i]) {
			keyma++;
		}
		if (sa == ma-a[i]) {
			keymi++;
		}
		
	}
	cout << res+min(keyma,keymi) << endl;
}
