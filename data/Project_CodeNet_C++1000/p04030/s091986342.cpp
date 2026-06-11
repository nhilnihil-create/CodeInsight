#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  string s;
  cin>>s;
  string s1;
  rep(i,s.size()){
    if(s[i]=='1'){
      s1+='1';
    }
    if(s[i]=='0'){
      s1+='0';
    }
    if(s[i]=='B'&&s1.size()!=0){
      s1.pop_back();
    }
  }
  cout<<s1<<endl;
}