#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  string ans="";
  cin>>S;
  for(int X=0;X<S.size();X++){
    if(S[X]=='1'||S[X]=='0'){
      ans.push_back(S[X]);
    }
    else if(S[X]=='B'&&ans.size()!=0){
      ans.erase(ans.size()-1);
    }
  }
  cout<<ans<<endl;
}
