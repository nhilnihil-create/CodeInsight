#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++) 
#define ll long long
#define MOD 1000000007
using namespace std;

int main() {
  string S; cin >> S;
  S = S.substr(0,S.size()-2);
  int ans =0; bool check = true;
  for(int i =S.size()/2; i>0; i--) {
    check = true;
    rep(j,0,i) {
      if (S[j] != S[i+j]) check = false;
    }
    if (check) {
      ans =i*2; break;
    }
  }
  cout << ans << endl;
}