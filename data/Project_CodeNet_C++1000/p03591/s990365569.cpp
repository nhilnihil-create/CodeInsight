#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  string ans = "Yes";
  if(S.size() < 4){
    ans = "No";
  }
  else if(S.at(0) != 'Y'){
    ans = "No";
  }
  else if(S.at(1) != 'A'){
    ans = "No";
  }
  else if(S.at(2) != 'K'){
    ans = "No";
  }
  else if(S.at(3) != 'I'){
    ans = "No";
  }
  cout << ans << endl;
}