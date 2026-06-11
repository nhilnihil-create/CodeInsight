#include <iostream>
using namespace std;
int main()
{
	char s[19];
	for(int i=0;i<19;i++)
	{
		cin>>s[i];
		if(s[i]==',')
		{
			s[i]=' ';
		}
	}
	for(int j=0;j<19;j++)
	{
		cout<<s[j];
	}
	return 0;
}