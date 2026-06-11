#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int a;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 2 == 1) {
			sum++;
		}
	}

	if (sum % 2 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}