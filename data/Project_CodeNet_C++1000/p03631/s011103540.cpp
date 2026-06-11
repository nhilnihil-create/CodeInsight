#include<bits/stdc++.h>
using namespace std;
int main(){
  string s; cin >> s;
  int n = (int)s.size();
  bool f = true;
  for(int i = 0; i < n; ++i){
    f &= s[i] == s[n-i-1];
  }
  cout << (f?"Yes":"No") << endl;
}