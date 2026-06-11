#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin>>str;
	char a[200200];
	a[0]='Q';
	int length=0;
	for(int i=0;i<str.length();i++)
	{
	    if(str[i]=='T'&&a[length]=='S')
	    {
	    	length--;
		}
		else
		{
			length++;
			a[length]=str[i];
		}
	}
	cout<<length;
	return 0;
}