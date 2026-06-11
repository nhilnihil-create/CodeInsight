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
  lli x;cin>>x;
	lli modResult = x%11;
  lli ans=(lli)x/11 * 2;
	if(modResult<7 && modResult>0)
		++ans;
	else if(modResult>=7)
		ans+=2;
	cout<<ans;
	return 0;
}
