#include<bits/stdc++.h>
using namespace std;
int x,y;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<4;i++)
	{
		cout<<s[i];
	}
	cout<<' ';
	for(int i=4;i<s.size();i++)
	{
		cout<<s[i];
	}
	cout<<endl;
    return 0;
}