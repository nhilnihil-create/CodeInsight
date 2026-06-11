#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int flag=0,ans=0;
	cin>>s;
	int a=s.length();
	for(int i=0;i<a;i++)
	{
		if(s[i]=='S')
		flag++;
		if((flag)&&s[i]=='T')
		{
			flag--;
			ans+=2;
		}
	}
	cout<<a-ans<<endl;
}
