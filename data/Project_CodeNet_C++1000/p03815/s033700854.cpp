#include <iostream>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	if ((n - 1) % 11 > 5) {
		cout << (n + 10) / 11 * 2 << endl;
	}
	else {
		cout << n / 11 * 2 + 1 << endl;
	}

	return 0;
}