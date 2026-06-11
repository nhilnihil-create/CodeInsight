#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{	
	int t;
	cin >> t;
	ll a=1, b=1, t1, t2, n;
	while (t--)
	{
		cin >> t1 >> t2;
		n = max(a / t1, b / t2);
		if (n * t1 < a || n * t2 < b)n++;
		a = n * t1, b = n * t2;
	}
	cout << a + b;
}