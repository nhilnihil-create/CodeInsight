#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int counts=0;
	int count=0;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='T'&&counts!=0)
		{
			counts--;
			count--;
		}
		else if(s[i]=='S')
		{
			counts++;
			count++;
		}
		else
		{
			count++;
		}
	}
	cout<<count;
} 