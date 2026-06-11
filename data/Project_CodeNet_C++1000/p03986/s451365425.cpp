#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
//	int len=s.length();
	for(int i=0;i<s.size()-1&&s.size()>0;i++)
	//for(int i=0;i<len-1&&len>0;i++)
	{
		if(s[i]=='S'&&s[i+1]=='T')
		{
			s.erase(i,2);
			if(i==0)
			{
				i--;
			}
			else
			{
				i=i-2;
			}
		}
	}
	cout<<s.size()<<endl;
	return 0;
}