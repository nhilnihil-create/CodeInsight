#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n; cin >>n;
  vector<long long>a(n),b(n);
  for(long long i=0;i<n;i++)cin>>a[i]>>b[i];
  long long kazu=0;
  for(long long i=n-1;i>=0;--i){
    long long tmp=b[i]-(a[i]+kazu)%b[i];
    if((a[i]+kazu)%b[i]!=0)kazu+=tmp;
    tmp=kazu;
  }
  cout<<kazu<<endl;
  return 0;
}