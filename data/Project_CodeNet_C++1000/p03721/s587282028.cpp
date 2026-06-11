#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
  sort(v.begin(),v.end());
  ll c=0;
  for(int i=0;i<n;i++)
    {
        c+=v[i].second;
        if(c>=k)
        {
            cout<<v[i].first;
            break;
        }
    }
}
