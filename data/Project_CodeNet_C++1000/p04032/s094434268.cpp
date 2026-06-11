#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int n=s.size();
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==s[i+1]&&i+1<n)
			{
		
				cout<<i+1<<" "<<i+2<<"\n";
				flag=1;
				break;
			}
			if(s[i]==s[i+2]&&i+2<n)
			{
				cout<<i+1<<" "<<i+3<<"\n";
				flag=1;
				break; 
			}
		}
		if(!flag)
		cout<<-1<<" "<<-1<<"\n";	
	}

	return 0;
} 