#include<bits/stdc++.h>
using namespace std;
int pd(char c)
{
	if(c=='b') return 1;
	if(c=='d') return 4;
	if(c=='p') return 2;
	if(c=='q') return 3;
}
int main()
{
	string s;
	cin>>s;
	int flag=0;
	for(int i=0;i<=s.length()-1;i++)
	{
		if(pd(s[i])+pd(s[s.length()-1-i])!=5)
		{
			flag=1;
			break;
		}
		
		
	}
	if(flag==1) cout<<"No";
	else cout<<"Yes";

 return 0;
}
