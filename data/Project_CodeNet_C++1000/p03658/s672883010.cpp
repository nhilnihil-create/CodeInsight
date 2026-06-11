#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.rbegin(),a.rend());
  long long kotae=0;
  for(int i=0;i<k;i++){
    kotae+=a[i];
  }
  cout<<kotae<<endl;
  return 0;
}
