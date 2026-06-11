#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,t,m=0; cin>>n;
  int a[100100]={0}; for(int i=0;i<n;i++) cin>>t,a[t]++;
  for(int i=1;i<100001;i++) m=max(m,a[i-1]+a[i]+a[i+1]);
  cout<<m<<endl;
}