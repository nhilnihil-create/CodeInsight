#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  deque<char> ans;
  
  
  for(int i=0;i<S.size();i++){
    if(S[i]=='0'){
      ans.push_back('0');
    }
    else if(S[i]=='1'){
      ans.push_back('1');
    }
    else if(S[i]=='B'){
      if(!(ans.empty())){
        ans.pop_back();
      }
    }
  }
  
  while(!(ans.empty())){
    cout<<ans.front();
    ans.pop_front();
  }
}