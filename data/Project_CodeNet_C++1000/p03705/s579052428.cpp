#include <bits/stdc++.h>

using namespace std;

int main() {
	
	long long n, a,b;
	cin >> n >> a >> b;

	long long min = (n - 1)*a + b;
	long long max = a + (n - 1)*b;
	
	cout << (max - min + 1 >0? max - min + 1 : 0) << endl;

	return 0;
}