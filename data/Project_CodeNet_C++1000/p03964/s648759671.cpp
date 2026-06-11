#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long int takahashi = 0;
  long long int aoki = 0;
  for(int i=0;i<n;i++) {
    long long int t, a;
    cin >> t >> a;
    if(i == 0) {
      takahashi = t;
      aoki = a;
      continue;
    }
    long long int taka, ao;
    if(takahashi % t == 0) {
      taka = takahashi;
      ao = a * (takahashi / t);
    } else {
      taka = t * (takahashi / t + 1LL);
      ao = a * (takahashi / t + 1LL);
    }
    if(ao >= aoki) {
      takahashi = taka;
      aoki = ao;
      continue;
    }
    if(aoki % a == 0) {
      ao = aoki;
      taka = t * (aoki / a);
    } else {
      ao = a * (aoki / a + 1LL);
      taka = t * (aoki / a + 1LL);
    }
    takahashi = taka;
    aoki = ao;
  }

  cout << takahashi + aoki << endl;
}