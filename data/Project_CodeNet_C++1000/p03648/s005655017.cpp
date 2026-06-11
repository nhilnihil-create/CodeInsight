#include <iostream>
#include <limits.h>
using namespace std;

int main() {
	long long k;
	cin >> k;
	long long n = 50;
	cout << n << endl;
	
	long long sho = k / n, amari = k % n;
	long long kihon = 49 + sho;
	
	for (int i = 0; i < n - amari; i++) cout << kihon - amari << " ";
	for (int i = n - amari; i < n - 1; i++) cout << kihon + n + 1 - amari << " ";
	if (amari != 0) cout << kihon + n + 1 - amari << endl;
	
}
