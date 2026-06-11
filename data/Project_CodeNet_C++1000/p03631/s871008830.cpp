#include <iostream>
using namespace std;

int main() {
	int n, m = 0, nd;
	cin >> n;
	nd = n;
	m += (nd % 10) * 100;
	nd /= 10;
	m += (nd % 10) * 10;
	nd /= 10;
	m += nd;
	cout << (n == m ? "Yes" : "No") << endl;
	return 0;
}