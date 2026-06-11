#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
int a,b,c;
cin>>a>>b>>c;
int a1=a+b;
int a2=b+c;
int a3=c+a;
if (a1 <= a2 && a1 <= a3) 
        cout << a1 ; 
  
    else if (a2 <= a1 && a2 <= a3) 
        cout << a2; 
  
    else
        cout << a3 ; 
  
} 