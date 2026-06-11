#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int w, a, b;
	cin >> w >> a >> b;

	if (a < b) {
		cout << max(b - a - w, 0) << endl;
	}
	else {
		cout << max(a - b - w, 0) << endl;
	}

	return 0;
}