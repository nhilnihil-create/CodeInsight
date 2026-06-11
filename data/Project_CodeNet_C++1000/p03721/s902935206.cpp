#include <bits/stdc++.h>
using namespace std;

int main () {
  long long N,K;
  cin >> N >> K;
  vector<pair<long long,long long>> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p.at(i).first >> p.at(i).second;
  }
  sort(p.begin(), p.end());
  
  long long num;
  long long mae = 0;
  for (int i = 0; i < N; i++) {
    mae += p.at(i).second;
    if (mae >= K){
      cout << p.at(i).first << endl;
      return 0;
    }
  }
}