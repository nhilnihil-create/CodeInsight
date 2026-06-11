#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define llmax LLONG_MAX   //ranges are defined in climits
#define llmin LLONG_MIN
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
  int k,s;
  cin>>k>>s;
  lli ans=0;
  for(int x=0;x<=k;x++)
  {
    for(int y=0;y<=k;y++)
    {
      if(s-x-y>=0 && s-x-y<=k)
      {
        ++ans;
      }
    }
  }
  cout<<ans;
	return 0;
}