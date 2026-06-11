#include <bits/stdc++.h>
using namespace std;
int main(){
int a=0;
int c=0;
string S; cin>>S;
for(int i=0; i<S.size();i++){
if(S.at(i)=='S')
a++;
else{
if(a>0)
a--;
else
c++;}}
cout<<a+c<<endl;}
