#include<iostream>
using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	if (n - m <= 1 && m - n <= 1) { cout << "Brown" << endl; }
	else { cout << "Alice" << endl; }
}