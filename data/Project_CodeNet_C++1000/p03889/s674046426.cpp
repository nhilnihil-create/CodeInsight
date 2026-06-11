#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<=l/2;i++)
	{
		if(s[i]=='b'&&s[l-i-1]!='d'||s[i]=='d'&&s[l-i-1]!='b'||s[i]=='p'&&s[l-i-1]!='q'||s[i]=='q'&&s[l-i-1]!='p')
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
}