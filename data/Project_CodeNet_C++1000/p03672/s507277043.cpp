#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	string str;
	cin>>str;
	int len = str.length();
	int c{};
	for(int i=len-3;i>0;i-=2)
	{
		c = 0;
		for(int j = 0;j<(i+1)/2;j++)
			if(str[j] == str[(i+1)/2+j])
				c++;
		if(c == (i+1)/2)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<"0"<<endl;
	return 0;
}