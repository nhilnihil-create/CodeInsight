#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> f(26, -1);
  string s;
  cin>>s;
  for (char c: s) {
    f[c-'a']=1;
  }
  for (int i=0; i<26; i++) {
    if (f[i]==-1) {
      cout<<char(i+'a')<<endl;
      return 0;
    }
  }
  cout<<"None\n";
  return 0;
}