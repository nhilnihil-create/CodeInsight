#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  long n,a[200000],sum[200000];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];

  long cnt1 = 0;
  for(int i = 0; i < n; i++) {
    if(i == 0) sum[i] = a[i];
    else sum[i] = sum[i-1] + a[i];

    if(i % 2 == 0 & sum[i] <= 0) {
      cnt1 += abs(sum[i]) + 1;
      sum[i] = 1;
    }
    else if(i % 2 == 1 & sum[i] >= 0) {
      cnt1 += abs(sum[i]) + 1;
      sum[i] = -1;
    }
  }
  long cnt2 = 0;
  for(int i = 0; i < n; i++) {
    if(i == 0) sum[i] = a[i];
    else sum[i] = sum[i-1] + a[i];

    if(i % 2 == 0 & sum[i] >= 0) {
      cnt2 += abs(sum[i]) + 1;
      sum[i] = -1;
    }
    else if(i % 2 == 1 & sum[i] <= 0) {
      cnt2 += abs(sum[i]) + 1;
      sum[i] = 1;
    }
  }

  cout << min(cnt1,cnt2) << endl;
  return 0;
}