#include <iostream>
using namespace std;

int main() {
	int n;
	cin >>n;
	long long r1 = 1;
	long long r2 = 1;
	long long x[n];
	long long y[n];
	for (int i=0; i
         <n; i++){
		cin >> x[i] >> y[i];
	}
	long long a=x[0], b=y[0];
	for (int i=1; i<n; i++){
		r1 = (a-1)/x[i]+1;
		r2 = (b-1)/y[i]+1;
		long long r = max(r1, r2);
		a = r*x[i];
		b = r*y[i];
		//cout << a << ' ' <<b << endl;
	}
	cout << a+b << endl;
}