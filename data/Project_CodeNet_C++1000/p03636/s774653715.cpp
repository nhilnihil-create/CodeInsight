#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	cout<<s[0];
	if(s.size()>2)
	{
		cout<<s.size()-2;	
	}
	cout<<s[s.size()-1]<<endl; 
}