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
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i];
  long ans=0;
  for(int i=n;i>=1;i--)
  {
    int md=(ans+aa[i])%bb[i];
    if(md==0)md=bb[i];
    ans+=bb[i]-md;
  }
  cout<<ans<<endl;
  return 0;
}