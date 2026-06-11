#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<queue>
#include<cmath>
#include<memory.h>
#include<ctime>
#include<cstdio>

using namespace std;

int main()
{
	string s;
	cin>>s;
	string tmp=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='b')
		{
			s[i]='d';
		}			
		else 		
		{
			if(s[i]=='d')
			{
				s[i]='b';
			}
			else 
			{
				if(s[i]=='q')
				{
					s[i]='p';
				}			
				else 
				{
					if(s[i]=='p')
					{
						s[i]='q';
					}			
				}				
			}			
		}		
	}
	if(s==tmp)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}
