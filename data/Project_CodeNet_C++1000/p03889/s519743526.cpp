#include <bits/stdc++.h>
using namespace std;

char s[100001],s2[100001];

int main(){
	int len,i;
    gets(s);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(len-i-1>=0)
		{
			if(s[i]=='b') s2[len-i-1]='d';
		    if(s[i]=='d') s2[len-i-1]='b';
		    if(s[i]=='p') s2[len-i-1]='q';
		    if(s[i]=='q') s2[len-i-1]='p';
		}
		
	}
	for(i=0;i<len;i++)
	{
		if(s[i]!=s2[i]) 
		{
			cout<<"No"<<endl;
			return 0;
		}
		
	}
	cout<<"Yes"<<endl;
    return 0;
}