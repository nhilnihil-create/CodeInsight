#include<iostream>
#include<cstring>
using namespace std;
char s[100010],s1[100010],s2[100010];
int main()
{
	ios::sync_with_stdio(false);
	cin>>s+1;
	int l=strlen(s+1);
	for(int i=1;i<=l;i++)
	  s1[i]=s[l-i+1];
	for(int i=1;i<=l;i++)
	  {
	  	if(s1[i]=='b')
	  	  s2[i]='d';
	  	if(s1[i]=='d')
	  	  s2[i]='b';
	  	if(s1[i]=='p')
	  	  s2[i]='q';
	  	if(s1[i]=='q')
	  	  s2[i]='p';
	  }
	for(int i=1;i<=l;i++)
	  if(s2[i]!=s[i])
	    {
	    	cout<<"No";
	    	return 0;
		}
	cout<<"Yes";
	return 0;
}