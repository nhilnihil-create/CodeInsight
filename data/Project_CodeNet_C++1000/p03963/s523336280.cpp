#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,k;
  cin>>n>>k;
  long long kotae=k;
  for(int i=1;i<n;i++)kotae*=(k-1);
  cout<<kotae<<endl;
  return 0;
}