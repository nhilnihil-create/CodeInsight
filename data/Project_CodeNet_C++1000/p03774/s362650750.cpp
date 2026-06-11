
#include<bits/stdc++.h>
using namespace std;
  #define ll long long

int main()
{
  ll n,m;
  cin >> n >> m;
  vector<pair<ll,ll> > v,d ;
  for(int i=0; i<n; i++)
  {
      ll a,b;
      cin >> a >> b;
      v.push_back({a,b});
  }for(int i=0; i<m; i++)
  {
      ll a,b;
      cin >> a >> b;
      d.push_back({a,b});
  }
  for(int i=0; i<n; i++)
  {
      ll x=v[i].first;
      ll y=v[i].second,mx=INT_MAX,pos;
      for(int j=0; j<m; j++)
      {
          ll a = d[j].first;
          ll b = d[j].second,dis;
          dis = abs(x-a) + abs(y-b);
          //cout << a << " " << b << endl;
        //  cout << dis << endl;
         if(dis<mx)
         {
             mx = dis;
             pos = j+1;
         }

      }
    //  cout << mx << endl;
      cout << pos << endl;
  }

}
