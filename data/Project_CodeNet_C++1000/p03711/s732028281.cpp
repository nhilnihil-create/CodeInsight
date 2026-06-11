#include <iostream>
#include <cstdio>
using namespace std;

string s=".181010110101";
int x, y;
int main() {
	cin >> x >> y;
	cout << (s[x]==s[y]? "Yes" : "No");
	return 0;
}
