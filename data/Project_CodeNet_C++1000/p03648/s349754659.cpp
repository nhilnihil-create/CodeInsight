#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k;
	cin >> k;
	
	if (k == 0)
	{
		cout << "2\n1 1";
		return 0;
	}
	else if (k == 1)
	{
		cout << "2\n2 0";
		return 0;
	}
	
	if (k < 50)
	{
		cout << k << endl;
		
		for (int i = 0; i < k; i++)
			cout << k << " ";
	}
	else
	{
		if (k % 50 == 0)
		{
			cout << "50\n";
			
			for (int i = 0; i < 50; i++)
				cout << k/50+49 << " ";
		}
		else
		{
			cout << "50\n";
			
			for (int i = 0; i < k%50; i++)
				cout << k/50+50 << " ";
				
			for (int i = 0; i < 50-k%50; i++)
				cout << k/50+49-k%50 << " ";
		}
	}
}