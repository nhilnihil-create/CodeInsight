#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  string S;
  cin >> S;
  set<char> s;
  rep(i,S.size()){
    s.insert(S[i]);
  }
  if(s.size() == S.size()){
    cout << "yes";
  }
  else{
    cout << "no";
  }
}