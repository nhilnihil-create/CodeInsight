#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int N;
  cin >> N;
  
  map<ll, int> stick;
  vector<ll> length;
  
  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    
    stick[x]++;
    
    if (stick[x] != 0 && !(stick[x] % 2)) {
      length.push_back(x);
    }
  }
  
  sort(length.begin(), length.end(), greater<ll>());
  
  if (length.size() <= 1) {
    cout << 0 << endl;
  } else {
    cout << length[0] * length[1] << endl;
  }
    
}