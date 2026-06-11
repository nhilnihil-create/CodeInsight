#include <iostream>
using namespace std;
typedef long long int LLI;

bool examine( string & s, int & cut )
{
	int tmp;
	for(int i = 0; i < (s.size() - cut)/2; i++)
	{
		tmp = (s.size() - cut)/2;
		if( s[i] != s[tmp+i] )
			return false;
	}
	return true;
}

int length( string & s )
{
	int cut = 2;
	while( s.size() - cut != 0 )
	{
		if( examine(s,cut) == true )
			return s.size() - cut;
		cut += 2;
	}
	return 0;
}

int main()
{
	string s;
	cin >> s;
	cout << length(s);
}