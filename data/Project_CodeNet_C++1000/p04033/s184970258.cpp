#include<bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;
int main(){
  long long a,b;
  string S;
  cin>>a>>b;
  if(0>=a && 0<=b) S="Zero";
  else if(a>0) S="Positive";
  else if((b-a+1)%2==1) S="Negative";
  else S="Positive";
  cout<<S<<endl;
}
