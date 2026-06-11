#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
  string s,a;
  int cnt=0;
  cin>>s;
  a="CODEFESTIVAL2016";
  for(int i=0;i<s.size();i++){
    if(s[i]!=a[i]) cnt++;
  }
  cout<<cnt<<endl;
}
