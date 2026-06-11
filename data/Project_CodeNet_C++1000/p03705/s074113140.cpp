#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define testcase ll T; cin >> T; for (ll tc = 1; tc <= T; tc++)

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //testcase {
  ll n,a,b,mn,mx,ans;
  cin>>n>>a>>b;
  mn=(n-1)*a+b;
  mx=(n-1)*b+a;
  ans=mx-mn+1;
  if(ans>0) { cout<<ans; }
  else { cout<<0; }
  //}
  return 0;
}