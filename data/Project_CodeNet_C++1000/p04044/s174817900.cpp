#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	string s;
	long long n, l;
	cin >> n >> l;
	string arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	for(int i = 0; i < n; i++) {
		s += arr[i];
	}
	cout << s;
	return 0;
}