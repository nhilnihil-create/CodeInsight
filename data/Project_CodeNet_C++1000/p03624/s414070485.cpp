#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  string S;
  cin >> S;
  map <char, ll> mp;
  rep(i,S.size()){
    char C = S[i];
    mp[C]++;
  }
  char X = 'a';
  rep(i,26){
    if(mp[X] == 0){
      cout << X;
      return 0;
    }
    X++;
  }
  cout << "None";
}