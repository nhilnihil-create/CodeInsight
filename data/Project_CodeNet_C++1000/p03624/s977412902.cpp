#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  set<char> cs;
  for (char c: s) {
    cs.insert(c);
  }
  if (cs.size() == 26) {
    cout<<"None"<<endl;
    return 0;
  }
  for (int i='a'; i<='z'; i++) {
    if (cs.find(i) == cs.end()) {
      cout<<(char)i<<endl;
      return 0;
    }
  }
}