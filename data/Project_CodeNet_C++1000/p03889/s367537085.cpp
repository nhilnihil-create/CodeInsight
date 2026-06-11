#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    string b=a;
    a="";
    int x=b.size();
    int i;
    for (i=0;i<x;i++)
		a=b[i]+a;
    for(int i=0;i<x;i++)
	{
        if(a[i]=='b')
			a[i]='d';
        else if(a[i]=='d')
			a[i]='b';
        else if(a[i]=='p')
			a[i]='q';
        else if(a[i]=='q')
			a[i]='p';
    }
    if(a==b)
		cout<<"Yes"<<endl;
    else
		cout<<"No"<<endl;
    return 0;
}