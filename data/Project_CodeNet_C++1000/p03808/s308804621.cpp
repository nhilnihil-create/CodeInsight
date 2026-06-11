#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin>>n;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];
  long long sum = 0;
  for (int i=0; i<n; i++) {
    sum += a[i];
  }
  if (sum % (n * (n + 1) / 2) != 0) {
    cout<<"NO"<<endl;
    return 0;
  }
  long long k = sum / (n * (n + 1) / 2);
  for (int i=0; i<n; i++) {
    if (a[i] < k || a[i] > n * k) {
      cout<<"NO"<<endl;
      return 0;
    }
  }
  long long cnt = 0;
  for (int i=0; i<n; i++) {
    int j = (i + 1) % n;
    if (a[j] - a[i] == k) {
      continue;
    }
    long long tmp = k + a[i] - a[j];
    if (tmp % n != 0) {
      cout<<"NO"<<endl;
      return 0;
    }
    cnt += tmp / n;
  }
  if (cnt == k) {
    cout<<"YES"<<endl;
  } else {
    cout<<"NO"<<endl;
  }
}