#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  string all = "abcdefghijklmnopqrstuvwxyz";
  cin >> S;
  set <char> a;
  for(int i = 0; i < S.size(); i++){
    a.insert(S.at(i));
  }
  vector<char> c;
  for(char b : all){
    if(!a.count(b)) c.push_back(b);
  }
  sort(c.begin(), c.end());
  if(c.size() > 0) cout << c.at(0) << endl;
  else cout << "None" << endl;
}
