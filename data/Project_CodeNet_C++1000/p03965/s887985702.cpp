#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	string s;
	cin >> s;
	int g = 0, p = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if( s[i] == 'g' )
			g++;
		else
			p++;
	}
	cout << ( g - p ) / 2;
}