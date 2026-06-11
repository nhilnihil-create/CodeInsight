#include <iostream>

using namespace std;

int arr[7];
int main () {
	// input
	int oddc = 0;
	for (int i = 0; i < 7; i ++) {
		cin >> arr[i];
		if (i == 0 || i == 3 || i == 4)
			if (arr[i] % 2 == 1)
				oddc ++;
	}
	
	if (oddc >= 2 && arr[0] >= 1 && arr[3] >= 1 && arr[4] >= 1) {
		cout << 1ll * 3 + ((arr[0] - 1) / 2 * 2) + ((arr[3] - 1) /2 * 2) + ((arr[4] - 1) /2 * 2) + arr[1] << endl;
		return 0;
	}
	cout << 1ll * (arr[0] / 2 * 2) + (arr[3] / 2 * 2) + (arr[4] / 2 * 2) + arr[1] << endl;
	return 0;
}

