#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int sum=str.length();
	int l=0,r=1;
	while(r<str.length())
	{
		if(str[l]=='S'&&str[r]=='T') 
		{
			str.erase(l,2);
			sum=sum-2;
			l--,r--;
		}
		else
		{
			l++,r++;
		}
	}
	cout<<sum<<endl;
	return 0;
 } 
