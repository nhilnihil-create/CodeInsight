#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()

{
 int a,b;
 cin>>a>>b;
 if(b==1 && a!=1 || (b>a && a!=1))
    cout<<"Bob"<<endl;
 else if((a>b && b!=1) || a==1 && b!=1)
    cout<<"Alice"<<endl;
 else if(a==b)
 cout<<"Draw"<<endl;
}
