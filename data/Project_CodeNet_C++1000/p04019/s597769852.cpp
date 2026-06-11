#include <bits/stdc++.h>
using namespace std;
int main() {
 string S;
 cin>>S;
 vector<bool>vec(4);
 int s=S.size();
for(int i=0; i<s; i++){
if(S.at(i)=='N'){
vec.at(0)=true;
}
else if(S.at(i)=='W'){
vec.at(1)=true;
}
else if(S.at(i)=='S'){
vec.at(2)=true;
}
else if(S.at(i)=='E'){
vec.at(3)=true;
}
}
if(vec.at(0)==true&&vec.at(1)==true&&vec.at(2)==true&&vec.at(3)==true){
cout<<"Yes"<<endl;
}
else if(vec.at(0)==true&&vec.at(1)==false&&vec.at(2)==true&&vec.at(3)==false)
cout<<"Yes"<<endl;
else if(vec.at(0)==false&&vec.at(1)==true&&vec.at(2)==false&&vec.at(3)==true)
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;}