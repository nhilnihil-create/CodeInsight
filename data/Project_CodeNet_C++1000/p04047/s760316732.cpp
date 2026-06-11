#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  vector<int>a(2*n);
  for(int i=0;i<2*n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  long long sum=0;  
  for(int i=0;i<n;i++){
    sum+=min(a[2*i],a[2*i+1]);
  }
  cout<<sum<<endl;
  return 0;
}