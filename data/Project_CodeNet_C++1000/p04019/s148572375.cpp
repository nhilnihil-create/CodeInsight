#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;



int main(){
  string S;
  cin >> S;
  map<char, bool> mp;
  // mp['W'] = mp['N'] = mp['S'] = mp['E'] = false;
  mp['W'] = false;
  mp['N'] = false;
  mp['S'] = false;
  mp['E'] = false;
  REP(i, (int)S.size()){
    mp[S[i]] = true;
  }
  bool ans = true;
  // cout << 'w' << mp['W'] << " N" << mp['N'] << " S" << mp['S'] << " E" << mp['E'] << endl;
  if(mp['W'] != mp['E']) ans =false;
  if(mp['S'] != mp['N']) ans = false;
  if(ans){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}
