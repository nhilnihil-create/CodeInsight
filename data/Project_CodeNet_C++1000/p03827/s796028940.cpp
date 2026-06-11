#include <iostream>
#include <string>
using namespace std ; 
int main() {
	int x = 0;
	int max = -10;
	string s;
	int n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'I')
		{
			x++;
			if (x > max)
			{
				max = x;
			}
		}
		else 
		{
			if (x > max)
			{
				max = x;
			}
			x--;
		}
	}
	cout << max << endl;
}