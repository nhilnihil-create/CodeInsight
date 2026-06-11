#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k,sum=0; cin>>n>>k;
  vector<int> l(n);
  for(int i=0; i<n; i++) cin>>l[i];
  sort(l.rbegin(),l.rend());
  for(int i=0; i<k; i++) sum+=l[i];
  cout<<sum;
}