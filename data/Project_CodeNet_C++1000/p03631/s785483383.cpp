#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
int a,r,sum=0;
cin>>a;
int temp=a;
while(temp!=0)
{
	r=temp%10;
	sum=(sum*10)+r;
	temp=temp/10;
	
}
if(a==sum)    
printf("Yes ");    
else    
printf("No");   

return 0;  
}