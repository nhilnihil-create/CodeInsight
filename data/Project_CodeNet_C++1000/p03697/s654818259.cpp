#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
/*
// 1 3 5 7 8 10 12
// 4 6 9 11
//2
int x,y;
cin>>x>>y;
if(x==1||y==1||x==3||y==3||x==5||y==5||x==7||y==7||x==8||y==8||x==10||y==10||x==12||y==12)
cout<<"Yes";
else if(x==4||y==4||x==6||y==6||x==9||y==9||x==11||y==11)
cout<<"Yes";
else if(x==2||y==2)
cout<<"Yes";
else
cout<<"No";
*/
int A,B;
cin>>A>>B;
int a1;
a1=A+B;
if(a1>=10)
cout<<"error";
else
cout<<a1;
   return 0; 
} 