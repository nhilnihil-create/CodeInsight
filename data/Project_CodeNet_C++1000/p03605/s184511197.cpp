#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin>>a;
  if(a%10==9||((a-a%10)%100)/10==9)cout<<"Yes";
  else cout<<"No";
}