
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()

{
  int x,y;
  cin>>x>>y;
  if((x+y)%3==0 || x%3==0 || y%3==0)
    cout<<"Possible"<<endl;
  else
    cout<<"Impossible"<<endl;


 return 0;
}






