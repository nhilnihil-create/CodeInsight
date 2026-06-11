#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N; cin >> N;
  ll cnt = 0;
  for(int i = 0; N > 0; i++) {
    N /= 2;
    cnt++;
  }
  cout << pow(2, cnt - 1) << endl;
}