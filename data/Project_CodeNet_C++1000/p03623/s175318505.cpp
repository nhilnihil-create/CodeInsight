#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
int a,x,b;
cin>>x>>a>>b;
int m=abs(x-a);
int n=abs(x-b);
if(m<n)
cout<<"A";
else
cout<<"B";
return 0;  
}