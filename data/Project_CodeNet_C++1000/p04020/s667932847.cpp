#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long ans=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];//ans+=(aa[i]/2);aa[i]%=2;
  }
  for(int i=1;i<n;i++)
  {
    ans+=aa[i]/2;aa[i]%=2;
    if(aa[i]==0)continue;
    if(aa[i+1])
      ans++,aa[i+1]--;
  }
  ans+=aa[n]/2;
  cout<<ans<<endl;
  return 0;
}