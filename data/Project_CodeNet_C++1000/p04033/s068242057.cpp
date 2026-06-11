#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;

	string ans = "Zero";
	if( a > 0 ) ans = "Positive";
	else if(  b < 0 ) {
		long long n = a - b + 1;
		if( n % 2 ) ans = "Negative";
		else ans = "Positive";
	}

	cout << ans << endl;
}
