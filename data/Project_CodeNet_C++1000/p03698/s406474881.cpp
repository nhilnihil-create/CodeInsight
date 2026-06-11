#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<char>s(S.size());
  for(int i=0; i<S.size(); i++)s.at(i)=S.at(i);
  
  sort(s.begin(), s.end());
  
  string ans = "yes";
  for(int i=0; i<S.size()-1; i++){
    if(s.at(i)==s.at(i+1))ans = "no";
  }
  
  cout << ans << endl;
}