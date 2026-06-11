#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1;
	s2=s1;
	int l=s1.length(),i;
	for(i=0;i<l/2;i++)
		swap(s2[i],s2[l-i-1]);
	//reverse(s2.begin(),s2.end());
	for(i=0;i<l;i++)
	{
		if(s2[i]=='b')s2[i]='d';
		else
		if(s2[i]=='d')s2[i]='b';
		else
		if(s2[i]=='p')s2[i]='q';
		else
		if(s2[i]=='q')s2[i]='p';
	}
	if(s2==s1)cout<<"Yes";
	else	cout<<"No";
	cout<<endl;
	return 0;
}