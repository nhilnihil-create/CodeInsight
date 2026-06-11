#include <bits/stdc++.h>
using namespace std;

int main() {

  long long n, a, b, c, d;
  cin>>n>>a>>b>>c>>d;
  if (b > a + (n - 1) * d || b < a - (n - 1) * d) {
    cout<<"NO"<<endl;
    return 0;
  }
  long long low = a, up = a;
  for (int i=2; i<n; i+=2) {
    low -= d - c;
    up += d - c;
    if (low + (n - i - 1) * c <= b && b <= up + (n - i - 1) * d) {
      cout<<"YES"<<endl;
      return 0;
    }
    if (low - (n - i - 1) * d <= b && b <= up - (n - i - 1) * c) {
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
}