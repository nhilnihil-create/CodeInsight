#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	string s;
	getline(cin,s);
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]==',')
			s[i]=' ';
	}
	
	cout<<s;
	return 0;
}