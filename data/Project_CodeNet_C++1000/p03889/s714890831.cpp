#include<bits/stdc++.h>
using namespace std;
char str[100002];
char str2[100002];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>str;
	reverse_copy(str,str+strlen(str),str2);
	if(!strcmp(str,str2))
	{
		cout<<"Yes\n";
		return 0;
	}
	for(int i=0,lon=strlen(str);i<lon;i++)
		if(str2[i]=='b'&&str[i]!='d')
		{
			cout<<"No\n";
			return 0;
		}
		else if(str2[i]=='d'&&str[i]!='b')
		{
			cout<<"No\n";
			return 0;
		}
		else if(str2[i]=='p'&&str[i]!='q')
		{
			cout<<"No\n";
			return 0;
		}
		else if(str2[i]=='q'&&str[i]!='p')
		{
			cout<<"No\n";
			return 0;
		}
	cout<<"Yes\n";
	return 0;
}