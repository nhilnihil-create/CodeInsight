#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >>s;
  string s1 = "YAKI";
  bool can = true;
  rep(i,4){
    if(s[i]!=s1[i]) can = false;
  }
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}