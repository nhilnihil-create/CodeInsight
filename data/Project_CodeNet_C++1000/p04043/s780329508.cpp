#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int ans = a + b + c;
	if (ans == 17) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}