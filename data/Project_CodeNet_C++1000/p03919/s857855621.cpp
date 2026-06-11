#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w,i,a;
  cin>>h>>w;
  vector<string>s(h*w);
  for(i=0;i<h*w;i++){
    cin>>s[i];
    if(s[i]=="snuke")a=i;
  }
  cout<<char(65+a%w)<<a/w+1<<endl;
}
