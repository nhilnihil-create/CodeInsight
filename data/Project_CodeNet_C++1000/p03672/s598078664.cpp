#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0;
  bool flag = false;

  for(int i=0; i<n; ++i){
    cnt = 0;
    string ns = s.erase(n-i-1);
    int nns = ns.size();
    if(nns%2==1) continue;
    for(int j=0; j<nns/2; ++j){
      if(ns[j]==ns[nns/2 + j]) ++cnt;
      if(cnt == nns/2) flag = true;
    }
    if(flag){
      cout << ns.size() << endl;
      return 0;
    }
  }

  return 0;
}
