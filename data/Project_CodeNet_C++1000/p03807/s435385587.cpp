#include <bits/stdc++.h>
using namespace std;
int main(){
long long H,W; cin>>H;
long long a=0;
long long b=0;
for(long long i=0;i<H;i++){
cin>>W;
if(W%2==0){
a++;}
else
b++;}
if(b%2==1){
cout<<"NO"<<endl;
}
else
cout<<"YES"<<endl;}