#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll K, S, cnt = 0;
  cin >> K >> S;
  for(ll x = 0; x <= K; x++) {
    for(ll y = 0; y <= K; y++) {
      if((S - x - y >= 0) && (S - x - y <= K)) cnt++;
    }
  }
  cout << cnt << endl;
}