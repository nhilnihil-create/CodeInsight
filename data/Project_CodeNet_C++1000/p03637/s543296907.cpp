#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a;
	int n2 = 0, n4 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 4 == 0) {
			n4++;
		}
		else if (a % 2 == 0) {
			n2++;
		}
	}

	if (n4 >= n / 2 || n4 * 2 + n2 >= n) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}