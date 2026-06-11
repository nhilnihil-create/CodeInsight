#include<bits/stdc++.h>
using namespace std;
char s1[100010],s2[100010];
int len;
int main()
{
	cin>>s1;
	for(int i=strlen(s1)-1; i>=0; i--)
	{
		s2[len++]=s1[i];
	}
	for(int i=0; i<strlen(s2); i++)
	{
		switch(s2[i])
		{
			case 'b':
			{
				s2[i]='d';
				break;
			}
			case 'd':
			{
				s2[i]='b';
				break;
			}
			case 'p':
			{
				s2[i]='q';
				break;
			}
			case 'q':
			{
				s2[i]='p';
				break;
			}
		}
	}
	if(strcmp(s1,s2)==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
