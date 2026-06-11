#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  string ans="";
  if(a>0){
    ans = "Positive";
  }else if(b>=0){
    ans = "Zero";
  }else{
    int n=b-a;
    if(n%2==1)
      ans = "Positive";
    else
      ans = "Negative";
  }
  cout << ans << endl;
  return 0;
}