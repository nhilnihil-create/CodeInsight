#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;	
	int len,i;
	cin>>s1;
	len=s1.size();
	for(i=len-1;i>=0;i--)
	{
		switch(s1[i])
		{
			case 'b':s2+='d';break;
			case 'd':s2+='b';break;
			case 'q':s2+='p';break;
			case 'p':s2+='q';break;
			default: s2+=s1[i];
		}
	}
//	cout<<s1<<endl<<s2;	
	if(s1==s2) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}