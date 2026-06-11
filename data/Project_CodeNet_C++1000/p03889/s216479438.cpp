#include<bits/stdc++.h>
using namespace std;
int pd(char c)
{
	if(c=='b') return 1;
	if(c=='d') return 4;
	if(c=='p') return 2;
	if(c=='q') return 3;
}
int main()
{
    string s;
    int i,x,flag=1;
    cin>>s;
    x=s.length();
    if(x%2) flag=0;
    if(flag)
    for(i=0;i<x/2;i++)
    {
    	if(pd(s[i])+pd(s[x-i-1])!=5)
    	{
    		flag=0;
    		break;
		}
	}
	if(flag==0) cout<<"No";
	else cout<<"Yes";

 return 0;
}
