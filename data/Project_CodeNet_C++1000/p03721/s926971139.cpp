#include <bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,k;
  cin >> n >> k;
  map<int,int64_t>kazu;
  int a,b;
  for(int i=0;i<n;i++){
    cin >> a >> b;
    kazu[a]+=b;
  }
  int64_t ans=0,c=0;
  for(auto x:kazu){
    c+=x.second;
    if(c>=k){
      ans=x.first;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}