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
  int n;cin>>n;
  
  int x=0,max_x=0;
  for(int i=0;i<n;i++)
  {
    char c; cin>>c;
    if(c=='I')
    ++x;
    else if(c=='D')
    --x;
    max_x = max(x,max_x);
  }
  cout<<max_x;
	return 0;
}