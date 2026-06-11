
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll> &b)
{
  return a.first<b.first;
}

int main()
{
  ll a,b;
  cin>>a>>b;
  vector<pair<ll,ll>> v;
  while(a--)
  {
    ll c,d;
    cin>>c>>d;
    v.pb(mk(c,d));
  }
  sort(v.begin(),v.end(),sortbysec);
  ll sum=b,ans;
  for(ll i=0;i<v.size();i++)
  {
    sum-=v[i].second;
    if(sum<=0)
    {
      ans=v[i].first;
      break;
    }
  }
  cout<<ans<<endl;
}
