#include<iostream>
#include<string.h>
using namespace std;

string s;
int cnt=0;
int main()
{
	cin>>s;
	int len=s.length();
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='S')
			cnt++;
		if(s[i]=='T')
		{
			if(cnt>0)
			{
				cnt--;
				len-=2;
			}
		}	
	} 
	cout<<len<<endl;
	return 0;
}