#include<bits/stdc++.h>
using namespace std;
int main(){
  set<char> alpha;
  for(int i = 0; i < 26; i++){
    alpha.insert('a' + i);
  }
  string s; cin >> s;
  for(int i = 0; i < s.size(); i++){
    char moji = s.at(i);
    alpha.erase(moji);
  }
  if(alpha.empty())
    cout << "None" << endl;
  else
  	cout << *begin(alpha) << endl;
}