#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
int n;
cin>>n;
int r,sum=0,c=0;
int temp=n;
while(temp!=0)
{
	r=temp%10;
	if(r==9)
{
	c=1;
	break;
}
	
	temp=temp/10;
}

if(c==1)
cout<<"Yes";
else 
cout<<"No";


return 0;  
}