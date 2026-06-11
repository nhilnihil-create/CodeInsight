#include<bits/stdc++.h>
using namespace std;
int main() {
  string s, alphabet = "abcdefghijklmnopqrstuvwxyz"; cin >> s;
  set<char> appeared;
  int size = s.size();
  for(int i = 0; i < size; i++) {
    appeared.insert(s.at(i));
  }
  bool noneornot = 0;
  char firstfound;
  for(int i = 0; i < 26; i++) {
    if(!(appeared.count(alphabet.at(i)))) {
      noneornot = 1;
      firstfound = alphabet.at(i);
      break;
    }
  }
  if(noneornot) {
    cout << firstfound << endl;
  }
  else {
    cout << "None" << endl;
  }
}