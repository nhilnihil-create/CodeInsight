#include <iostream>
using namespace std;

int count(int arr[], int n) {
	int c = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i] == n) c += 1;
	}
	return c;
}

int main() {
	int abc[3];
	cin >> abc[0] >> abc[1] >> abc[2];
	if (count(abc, 5) == 2 && count(abc, 7) == 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}