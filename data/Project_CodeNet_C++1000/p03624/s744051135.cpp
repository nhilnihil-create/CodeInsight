#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  vector<int> a(130, 0);
  for(int i=0; i<s.size(); ++i) ++a[s[i]];
  for(int i=97; i<=122; ++i){
    if(!a[i]) { cout << char(i) << endl; return 0; }
  }
  cout << "None" << endl;
}