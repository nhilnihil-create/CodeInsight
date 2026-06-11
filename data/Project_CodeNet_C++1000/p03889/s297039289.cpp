#include <bits/stdc++.h>
using namespace std;

bool ck(char c, char d) {
  if(c=='b') return d=='d';
  if(c=='d') return d=='b';
  if(c=='p') return d=='q';
  if(c=='q') return d=='p';
  return 0;
}

int main() {
  string s;
  cin >> s;
  bool f=s.size()%2==0;
  for(int i=0; i<s.size()/2; i++) {
    if(!ck(s[i],s[s.size()-1-i])) f=0;
  }
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
