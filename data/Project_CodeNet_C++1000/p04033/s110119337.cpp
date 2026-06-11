#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int a, b;
	cin >> a >> b;
	if ((a == 0 || b == 0) || (a > 0 && b < 0) || (a < 0 && b > 0))
	{
		cout << "Zero" << endl;
	}
	else if (a > 0 && b > 0)
	{
		cout << "Positive" << endl;
	}
	else
	{
		cout << (abs(a-b)%2==0?"Negative":"Positive") << endl;
	}
	return 0;
}