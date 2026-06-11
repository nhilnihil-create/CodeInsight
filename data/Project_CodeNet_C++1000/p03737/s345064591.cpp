#include <iostream>
using namespace std;
 
int main() {
	string a, b, c;
	cin >> a >> b >> c;
	int n1 = a[0]-'a';
	int n2 = b[0]-'a';
	int n3 = c[0]-'a';
	cout << char('A'+n1) << char('A'+n2) << char('A'+n3) << '\n';
}
