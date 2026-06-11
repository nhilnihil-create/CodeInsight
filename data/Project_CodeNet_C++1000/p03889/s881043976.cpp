#include<bits/stdc++.h>
using namespace std;
char a[100009];
int main()
{
	int x;
	cin >> a;
	x = strlen(a);
	if(x % 2 == 1)
	{
		cout << "No" << endl;
		return 0;
	}
	for(int i = 0; i <= x/2-1; i++)
	{
		if(a[i] == 'p' && a[x-i-1] != 'q')
		{
			cout << "No" << endl;
			return 0;
		}
		if(a[i] == 'q' && a[x-i-1] != 'p')
		{
			cout << "No" << endl;
			return 0;
		}
		if(a[i] == 'b' && a[x-i-1] != 'd')
		{
			cout << "No" << endl;
			return 0;
		}
		if(a[i] == 'd' && a[x-i-1] != 'b')
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}