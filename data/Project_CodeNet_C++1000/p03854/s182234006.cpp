#include <bits/stdc++.h>
using namespace std;

unordered_set<string> okWord;

string Extract(string &str, int s, int e) {
  string res;
  if (s<0) {return res;}
  for (int i=s; i<e; i++) {res+=str.at(i);}
  return res;
}
int NextStartIndex(string &str, int p) {
  for (int i=7; i>=5; i--) {
    if (okWord.count(Extract(str, p-i, p))) {return p-i;}
  }
  return -1;
}
int main() {
  okWord.insert("dream");
  okWord.insert("dreamer");
  okWord.insert("erase");
  okWord.insert("eraser");
  
  string S;
  cin >> S;
  int idx=S.size();
  while(idx > 0) {
    idx=NextStartIndex(S, idx);
  }
  if (idx == 0) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}
