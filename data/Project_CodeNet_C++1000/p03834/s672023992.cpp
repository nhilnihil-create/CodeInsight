#include<iostream>
using namespace std;
int main()
{
	char str[19];
	cin>>str;
	int i;
	for(i=0;i<19;i++)
	{
		if(str[i]==',')
		{
			cout<<" ";
		}
		else
		{
			cout<<str[i];
		}
	}
	return 0;
}