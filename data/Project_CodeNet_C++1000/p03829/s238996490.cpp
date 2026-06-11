#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long long n, a, b;
	cin >> n >> a >> b;
	unsigned long long prev;
	cin >> prev;
	unsigned long long ret = 0;
	for (unsigned long long i = 1; i < n; ++i) {
		unsigned long long cur;
		cin >> cur;
		ret += min((cur - prev) * a, b);
		prev = cur;
	}

	cout << ret << endl;

	return 0;
}