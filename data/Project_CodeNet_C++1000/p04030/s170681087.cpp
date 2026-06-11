#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,ans="";
  cin >> S;
  int N = S.size();
  for (int i=0; i < N; i++){
    if (S.at(i) == '0'){
     ans.push_back('0');
    }
    else if(S.at(i) == '1'){
     ans.push_back('1');
    }
    else if(ans.size()!=0){
    ans.erase(ans.size()-1);
    }
  }
    cout << ans << endl;
  return 0;
}
