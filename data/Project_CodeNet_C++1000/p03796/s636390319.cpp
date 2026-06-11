#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int N;
  cin >> N;
  ll a = 1;
  rep(i,N) a = a*(i+1)%1000000007;
  cout << a << endl;
  return 0;
}