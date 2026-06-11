#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	vector<string> arr(n);
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	string res = "";
	for (string str : arr) {
		res += str;
	}
	cout << res;
}
