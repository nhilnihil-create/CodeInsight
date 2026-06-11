#include <bits/stdc++.h>
using namespace std;

int main() {
int h,w;
cin>>h>>w;
vector<string> vec(h+2);
for(int i =0;i<h;i++){
cin>>vec.at(i+1);}
string p;
p="";
for(int i =0;i<w+2;i++){
p+="#";}
vec.at(0)=p;
vec.at(h+1)=p;
for(int i =0;i<h;i++){
vec.at(i+1)="#"+vec.at(i+1)+"#";}
for(int i = 0;i<h+2;i++){
cout<<vec.at(i)<<endl;}
}


