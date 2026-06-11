#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string s;
  cin>>s;
  int n;
  cin >> n;
  int to=n;
  rep(i,s.size()){
    if(n>0){
      if(s.at(i)!='a'&&'a'+26-s.at(i)<=n){
        n-='a'+26-s.at(i);
        s.at(i)='a';
      }
    }
  }
  n=(n+26)%26;
  int sa=s.at(s.size()-1)-'a';
  sa=(sa+n)%26;
  s.at(s.size()-1)='a'+sa;
  cout<<s<<endl;  
}