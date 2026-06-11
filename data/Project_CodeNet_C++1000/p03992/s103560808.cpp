#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<4;i++)
	{
		cout<<s.at(i);
	}
	cout<<" ";
	for(int i=4;i<s.size();i++)
	{
		cout<<s.at(i);
	}
  cout<<"\n";
	return 0;
}