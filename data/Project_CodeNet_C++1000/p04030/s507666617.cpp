#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  string s;
  cin >> s;
  int l=s.size();
  string ans;
  rep(i,l){
    if(ans.size()>=1 && s.at(i)=='B'){
      ans=ans.erase(ans.size()-1,1);
    }else if(s.at(i)!='B'){
      ans+=s.at(i);
    }
  }
  cout << ans;
}
    