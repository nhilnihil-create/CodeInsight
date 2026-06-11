#include <bits/stdc++.h>
using namespace std;
int main(){
long long a,b,c,d,e,f,g=0; cin>>a>>b>>c;
long long counter=0;
while((a%2==0&&b%2==0)&&(b%2==0&&c%2==0)){
d=a/2+b/2;
e=a/2+c/2;
f=b/2+c/2;
a=d;
b=e;
c=f;
counter++;
if((a==b&&b==c)){
g++;
break;}}
if(g==1){
cout<<-1<<endl;}
else
cout<<counter<<endl;}
