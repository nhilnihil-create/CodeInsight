#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  vector<int>a(n);
  long long sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int j,k;
    cin>>j>>k;
    long long kotae=sum-a[j-1]+k;
    cout<<kotae<<endl;
  }
  return 0;
}