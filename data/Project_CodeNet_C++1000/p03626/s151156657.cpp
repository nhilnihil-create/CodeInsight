#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  
  vector<pair<int, ll>> domino;
  
  int i = 0;
  while (i < N) {
    if (S[i] == S[i+1]) {
      ll count = 0;
      while(S[i] == S[i+1]) {
        i += 2;
        count++;
      
        if (i >= N) break;
      }
      pair<int, ll> p = make_pair(1, count);
      domino.push_back(p);
    }
    if (S[i] != S[i+1]) {
     ll count = 0;
      while(S[i] != S[i+1]) {
        i++;
        count++;
      
        if (i >= N) break;

      }  
      pair<int, ll> p = make_pair(0, count);
      domino.push_back(p);
    }
    
  }
    
  
  ll ans = 0;
  
  if (domino[0].first == 0) {
    ans = 3;
    for (int i = 0; i < domino[0].second - 1; i++) {
      ans *= 2;
    }
    
  } else {
    ans = 6;
    for (int i = 0; i < domino[0].second - 1; i++) {
      ans *= 3;
    }
  }
  
  for (int i = 1; i < domino.size(); i++) {
    
    if (domino[i].first == 0) {
      for (int j = 0; j < domino[i].second -1; j++) {
        ans *= 2;
        ans %= MOD;
    } 
    } else {  
      ans *= 2;
      for (int j = 0; j < domino[i].second -1; j++) {
        ans *= 3;
        ans %= MOD;
      }
  
    }
  }
  cout << ans << endl;
  
  
}