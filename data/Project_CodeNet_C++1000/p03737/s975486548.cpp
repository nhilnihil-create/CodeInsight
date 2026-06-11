#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	string a, aa, aaa;
	cin >> a >> aa >> aaa;
	char l1 = a[0];
	char l2 = aa[0];
	char l3 = aaa[0];
	l1-=32;
	l2-=32;
	l3-=32;
	cout << l1 << l2 << l3 << "\n";
}