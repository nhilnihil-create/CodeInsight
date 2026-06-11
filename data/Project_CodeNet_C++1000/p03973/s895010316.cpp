#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
//main
signed main(){
  int N;cin>>N;
  int ans=0;
  int mi=1;
  int z;cin>>z;ans+=z-1;
  for(int i=1;i<N;i++){
    int a;cin>>a;
    if(a<=mi+1){
      mi=max(a,mi);
      continue;
    }
    ans+=(a-1)/(mi+1);
  }
  cout<<ans<<endl;
}
