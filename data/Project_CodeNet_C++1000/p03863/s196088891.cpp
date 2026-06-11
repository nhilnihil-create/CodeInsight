#include <cstring>
#include <iostream>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
if(s.size()%2==0&&s.at(0)==s.at(s.size()-1))
cout<<"First"<<endl;
else if(s.size()%2==1&&s.at(0)==s.at(s.size()-1))
cout<<"Second"<<endl;
else if(s.size()%2==1)
cout<<"First"<<endl;
else
cout<<"Second"<<endl;}
