#include<bits/stdc++.h>
using namespace std;
char a[1000001],s[1000001];
int main()
{
    int b,sum=0,l=0;
    cin>>a;
    b=strlen(a);
    for(int i=b-1;i>=0;i--) 
	{
        s[sum]=a[i];
        if(s[sum]=='b') s[sum]='d';
        else if(s[sum]=='d') s[sum]='b';
        else if(s[sum]=='p') s[sum]='q';
        else if(s[sum]=='q') s[sum]='p';
        sum++;
    }
    for(int i=0;i<=b-1;i++) 
	{
        if(a[i]!=s[i])
		{
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
