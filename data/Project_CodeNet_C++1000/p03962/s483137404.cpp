#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int count = 3;
	if (a == b && b == c && a == c) count=1;
	else if (a != b && b != c && a != c) count=3;
	else count=2;
	cout << count << endl;
}
