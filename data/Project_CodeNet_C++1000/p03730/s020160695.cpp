#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 7;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int f = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		if (a * i % b == c)f = 1;
	}
	if (f)cout << "YES" << endl;
	else cout << "NO" << endl;
}