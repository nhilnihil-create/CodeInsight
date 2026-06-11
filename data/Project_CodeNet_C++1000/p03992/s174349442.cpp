#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	getline(cin,s);
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		cout<<s[i];
		if(i==3)  cout<<" ";
	}
	cout<<"\n";

	return 0;
}