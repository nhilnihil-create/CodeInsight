#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  vector<int>n(26,0);
  cin >> s;
  for(int i=0;i<s.size();i++){
    n.at(s.at(i)-97) +=1;
  }
  bool c = true;
  for(int i=0;i<26;i++){
    if(n.at(i)%2!=0){
      c = false;
      break;
    }
  }
  if(c)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}