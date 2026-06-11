#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,k;
  cin>>n>>k;
  long long cnt=0;
  vector<pair<long long,long long>>a(n);
  for(long long i=0;i<n;i++)cin>>a[i].first>>a[i].second;
  sort(a.begin(),a.end());
  for(long long i=0;i<n;i++){
    cnt+=a[i].second;
    if(k-1<cnt){
      cout<<a[i].first<<endl;
      return 0;
    }
  }
  return 0;
}
    