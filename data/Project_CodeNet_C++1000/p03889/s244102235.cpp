#include<bits/stdc++.h>
using namespace std;
int len;
char s[100005],s1[100005];
bool ok=1;
int main()
{
    cin>>s;
    len=strlen(s);
    for(register int i=0;i<len;i++)
    {
        s1[i]=s[len-i-1];
        if(s1[i]=='b')
        	s1[i]='d';
        else if(s1[i]=='d')
        	s1[i]='b';
        else if(s1[i]=='p')
        	s1[i]='q';
        else
        	s1[i]='p';
    }
    for(register int i=0;i<len;i++)
    {
    	if(s[i]!=s1[i])
    	{
    		ok=0;
    		break;
        }
    }
    if(ok)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}