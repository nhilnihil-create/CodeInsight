#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

long long x[N];

int main ()
{
	long long n, a, b;
	cin >> n >> a >> b;
	for (int i = 0 ; i < n ; i ++) {
		cin >> x[i];
	}
	long long sum = 0;
	for (int i = 1; i < n ; i++) {
		sum += min((x[i]-x[i-1]) * a, b);
	}
	cout << sum << endl;
	return 0;
}
