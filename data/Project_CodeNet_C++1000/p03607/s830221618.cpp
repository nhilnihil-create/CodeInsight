#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int64_t,int>kami;
  int64_t a;
  for(int i=0;i<n;i++){
    cin >> a;
    kami[a]=(kami[a]==1)?0:1;
  }
  int ans=0;
  for(auto x:kami)
    if(x.second==1)
      ans++;
  cout << ans << endl;
  return 0;
}