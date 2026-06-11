#include <bits/stdc++.h>
using namespace std;
int main()
{
   int a, b, sum = 0;
	cin >> a >> b;
	sum = a + b;
	if (sum % 3 == 0)
		cout << "Possible"<<endl;
	else if (sum == 0)
		cout << "Impossible"<<endl;
	else if (b % 3 == 0 || a % 3 == 0)
		cout << "Possible"<< endl;
	else
		cout << "Impossible"<<endl;
return 0;
}