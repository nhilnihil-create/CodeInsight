#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
int x,t;
cin>>x>>t;
if(x<=t)
cout<<"0";
else if(x>t)
{

int c=x-t;
cout<<c;
}
return 0;  
}