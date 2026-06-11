#include<iostream>
using namespace std;
int main()
{
	string s,ss="CODEFESTIVAL2016";
	int ans=0;
	cin>>s;
	for (int i=0;i<s.size();i++)
		if(s[i]!=ss[i]) ans++;
	cout<<ans<<endl;
}