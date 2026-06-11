#include<iostream>
#include<algorithm>
using namespace std;
bool a[26];
int main()
{

	int x, a, b;
	cin >> x >> a >> b;
	if (abs(a - x) > abs(b - x))
		cout << "B";
	else
		cout << 'A';
}