#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
  cin>>a>>b>>c;
  if(a==b && b==c && c==a && a%2==0){cout<<-1;return 0;}
  int n=0,tempa,tempb,tempc;
  while(a%2==0 && b%2==0 && c%2==0){
  	tempa = (b+c)/2;
    tempb = (a+c)/2;
    tempc = (a+b)/2;
    n+=1;
    a = tempa;b=tempb;c=tempc;
  }
  cout<<n;
}