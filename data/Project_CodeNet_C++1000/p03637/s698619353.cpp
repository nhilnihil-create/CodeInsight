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
  int s2=0, s4=0, a;
  for (int i=0; i<N; i++) {
    cin >> a;
    if (a%4==0) {
      s4++;
    }
    else if (a%2==0) {
      s2++;
    }
  }
  if (s4>=N/2) {
    cout << "Yes" << endl;
  }
  else if ((N-s4*2)<=s2) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
 