#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e9 + 7;

int main()
{
	int w, a, b;
	cin >> w >> a >> b;
	if (b >= a + w)cout << b - a - w << endl;
	else
	{
		if (b + w >= a)cout << 0;
		else
		{
			cout << a - b - w << endl;
		}
	}
}