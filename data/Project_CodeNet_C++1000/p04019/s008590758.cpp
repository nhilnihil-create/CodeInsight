#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  int n=0, w=0, s=0, e=0;
  rep(i,S.size()) {
      if(S.at(i)=='N') n++;
      else if(S.at(i)=='W') w++;
      else if(S.at(i)=='S') s++;
      else if(S.at(i)=='E') e++;
  }
  if(n==0&&s!=0) cout << "No" << endl;
  else if(n!=0&&s==0) cout << "No" << endl;
  else if(e!=0&&w==0) cout << "No" << endl;
  else if(e==0&&w!=0) cout << "No" << endl;
  else cout << "Yes" << endl;
}