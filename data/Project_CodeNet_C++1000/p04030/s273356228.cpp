#include <bits/stdc++.h>
 #define rep(i,n) for(int i=0;i<n;i++)
 using namespace std;
  int main(){
      string s;
      cin >> s;
      string ans;
      rep(i,s.size()){
          if(s[i]!='B'){
              ans.push_back(s[i]);
          }
          else{
              if(ans.size()==0)continue;
              else ans.pop_back();
          }
      }
      cout << ans << endl;
  }