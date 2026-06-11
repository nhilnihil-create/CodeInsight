#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,char>;
using ll=long long;

int gcd (int a, int b) {
  int d=a;
  if (b!=0) {
    d=gcd(b, a%b);
  }
  return d;
}

int lcm (int a, int b) {
  return a*b/gcd(a,b);
}

int main() {
  int N;
  cin >> N;
  vector<ll> T(N);
  for (int i=0; i<N; i++) {
    cin >> T[i];
  }
  
  ll s=1;
  for (int i=0; i<N; i++) {
    s=lcm(T[i], s);
  }
  cout << s << endl;
}
 