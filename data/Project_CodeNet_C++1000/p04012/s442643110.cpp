#include <bits/stdc++.h>
using namespace std;

int main() {

  string w;

  cin >> w;
  vector<int> vec(26);
  for(int i=0;i<w.size();++i){
    vec.at(w.at(i)-'a')++;
  }

  for(int i=0;i<26;++i){
    if(vec.at(i) % 2 == 1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
