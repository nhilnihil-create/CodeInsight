#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++) {
		a[i] = 25000*(i+1);
		b[i] = 25000*(n-i);
	}
	for(int i = 0; i < n; i++) {
		int p;
		cin >> p;
		b[p-1] += i;
	}
	cout << a[0];
	for(int i = 1; i < n; i++) {
		cout << " " << a[i];
	}
	cout << endl;
	cout << b[0];
	for(int i = 1; i < n; i++) {
		cout << " " << b[i];
	}
	cout << endl;
}
