#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  map<ll,ll> mp;
  for (int i = 0; i < N; i++) {
    mp[A.at(i)]++;
  }
  
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  
  ll a, b = 0;
  for (int i = 0; i < N; i++) {
    if (mp[A.at(i)] >= 2) {
      if (a == 0) {
        a = A.at(i);
        if (mp[A.at(i)] >= 4) {
          b = A.at(i);
          break;
        }
      }
      if (a != 0 && a != A.at(i) && b == 0) {
        b = A.at(i);
        break;
      }
    }
  }

  ll c = a * b;
  cout << c << endl;
}