#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, sum = 0; cin >> n;
	vector<int>a(n); 
	for (auto&& x : a) {
		cin >> x;
		sum += x;
	}
	cout << (sum % 2 == 0 ? "YES" : "NO") << endl;

	return 0;
}