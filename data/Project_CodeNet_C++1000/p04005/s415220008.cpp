#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<long long> a(3);
  cin>>a[0]>>a[1]>>a[2];
  sort(a.begin(),a.end());
  if(a[0]%2==1&&a[1]%2==1&&a[2]%2==1) cout<<a[0]*a[1]<<endl;
  else cout<<0<<endl;
}
  