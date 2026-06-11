#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  vector<long> a(n),b(n);
  set<long> s;
  for(long i=0;i<n;i++) {
    cin >> a[i];
    b[a[i]-1]=i;
  }
  s.insert(-1);
  s.insert(n);
  for(long i=0;i<n;i++) {
    auto itr2=s.upper_bound(b[i]);
    itr2--;
    auto itr=itr2;
    itr2++;
    ans+=(i+1)*(b[i]-*(itr))*(*(itr2)-b[i]);
    s.insert(b[i]);
  }
  cout << ans << endl;
}