#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	vector<int> arr(3);
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr.begin(), arr.end());
	if (arr[0] == 5 && arr[1] == 5 && arr[2] == 7) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}	
}
