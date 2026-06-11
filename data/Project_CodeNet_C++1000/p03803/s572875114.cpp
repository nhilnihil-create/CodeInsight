#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	
	if(a==b)
		cout << "Draw";
	else
	{
		if(a>b && b!=1)
			cout << "Alice";
		else if(a>b && b==1)
			cout << "Bob";
		else if(a<b && a!=1)
			cout << "Bob";
		else if(a<b && a==1)
			cout << "Alice";
	}
		

	return 0;
}
