#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin>>s;
  string t;
  rep(i,s.size()){
    if(s[i]=='1')t+='1';
    if(s[i]=='0')t+='0';
    if(s[i]=='B'&&t.size()!=0)t.pop_back();
  }
  cout<<t<<endl;
}