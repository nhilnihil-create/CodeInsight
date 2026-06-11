#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, b;
	int min = 1010101010;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (min > b) {
			min = b;
			t = a;
		}
	}
	cout << min + t << endl;

	return 0;
}