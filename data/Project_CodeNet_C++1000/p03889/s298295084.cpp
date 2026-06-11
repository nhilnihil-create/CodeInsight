#include<bits/stdc++.h>
using namespace std;
char a[100010],s2[100010];
int len;
int main()
{
    cin>>a;
    for(int i=strlen(a)-1; i>=0; i--)
    {
        s2[len++]=a[i];
    }
    for(int i=0; i<strlen(a); i++)
    {
       if(a[i]=='b')
       {
       	a[i]='d';
       	continue;
	   }
	   if(a[i]=='d')
       {
       	a[i]='b';
       	continue;
	   }
	   if(a[i]=='q')
       {
       	a[i]='p';
       	continue;
	   }
	   if(a[i]=='p')
       {
       	a[i]='q';
       	continue;
	   }
    }
    if(strcmp(a,s2)==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}