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
  for(int i=1;i<=3*n;i++)cin>>aa[i];
  sort(aa+1,aa+3*n+1);
  long ans=0;
  for(int i=n+1;i<=3*n;i+=2)ans+=aa[i];
  cout<<ans<<endl;
  return 0;
}