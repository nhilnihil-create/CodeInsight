#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin>>n;
  long long x=3*n;
  vector<long long>a(x);
  for(long long i=0;i<x;i++){
    cin>>a[i];
  }
  long long ans=0;
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  for(long long i=0;i<n;i++){
    ans+=a[1+2*i];
  }
  cout<<ans<< endl;
  return 0;
}