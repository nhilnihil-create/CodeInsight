#include<bits/stdc++.h>
using namespace std;
int t=0;
string s,ch="CODEFESTIVAL2016";
int main()
{
	cin>>s;
	for(int i=0;i<16;i++)
	{
		if(s[i]!=ch[i]) t++;
	}
	cout<<t<<endl;
	return 0;
}