#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n,count=0;cin >> n;
  vector<long long> a(n);
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) {
    if (i+1==a[a[i]-1]) count++;
  }
  cout << count/2 << endl;
}
