#include<iostream>
using namespace std;

long long f(long long i, long long j) {
	return (i!=-1 ? i / j + 1 : 0);
}

int main() {
	long long a, b, x; cin >> a >> b >> x;
	cout << f(b, x) - f(a - 1, x) << endl;

	return 0;
}