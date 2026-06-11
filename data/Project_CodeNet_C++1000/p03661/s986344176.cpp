#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin>>N;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  int k=0;
  for(int i=0;i<N;i++)k+=v[i];
  int ans=100000000000000000;
  int kk=0;
  int tt;
  for(int i=0;i<N-1;i++){
    kk+=v[i];
    tt=abs(2*kk-k);
    ans=min(ans,tt);
  }
  cout<<ans<<endl;
}
