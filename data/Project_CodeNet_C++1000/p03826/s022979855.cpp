#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
    int a,b,c,d;
	cin>>a>>b>>c>>d;
	int a1,a2;
	a1=a*b;
	a2=c*d;
	if(a1<=a2)
	cout<<a2;
	else
	cout<<a1; 
   return 0; 
} 