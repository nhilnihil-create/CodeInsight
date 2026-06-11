#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  vector<long> a(n),b(n);
  set<long> x;
  for(long i=0;i<n;i++) {
    cin >> a[i];
    b[i]=a[i];
  }
  sort(b.begin(),b.end());
  for(long i=0;i<n;i+=2) x.insert(b[i]);
  for(long i=1;i<n;i+=2) if(x.count(a[i])) ans++;
  cout << ans << endl;
}