#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define piii pair<pii,pii>
#define precise cout<<fixed<<setprecision(10)
#define st first
#define nd second
#define ins insert
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
vi ans;
int32_t main()
{
  BOOST;
  int k;
  cin>>k;
  int n=50;
  for (int i=0;i<n;i++)ans.pb(i+k/n);
  int ile=k%n;
  for (int i=0;i<=ile-1;i++){
  	for (int j=0;j<n;j++){
  		if (i==j)ans[j]+=n;
  		else ans[j]--;
  	}
  }
  cout<<sz(ans)<<"\n";
  for (auto it:ans)cout<<it<<" ";
  return 0;
}
