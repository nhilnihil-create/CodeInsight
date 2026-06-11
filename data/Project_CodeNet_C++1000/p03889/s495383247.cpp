#include<bits/stdc++.h>
using namespace std;
int main()
{
	string jstr,xstr;
	int i;
	cin>>jstr;
	xstr=jstr;
	reverse(xstr.begin(),xstr.end());
	for(i=0;i<xstr.size();i++)
	{
		if(xstr[i]=='b')
			xstr[i]='d';
		else if(xstr[i]=='d')
			xstr[i]='b';
		else if(xstr[i]=='p')
			xstr[i]='q';
		else if(xstr[i]=='q')
			xstr[i]='p';
	}
	if(xstr==jstr)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0; 
}