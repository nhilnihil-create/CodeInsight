#include<bits/stdc++.h>
using namespace std;


int main(){
  long long n,t,i;
  cin >> n >> t;
  vector<long long> ti(n);
  for(i=0;i<n;++i){
    cin >> ti[i];
  }
  long long ans=0;
  bool bet=false;
  for(i=0;i<n-1;++i){
    ans+=min(t,ti[i+1]-ti[i]);
  }
  ans+=t;
  cout << ans << endl;
  return 0;
}
