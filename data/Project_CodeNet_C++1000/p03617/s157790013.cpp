#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  ll q,h,s,d;
  cin>>q>>h>>s>>d;
  ll n;
  cin>>n;
  q=q*4;
  h=h*2;
  vector<ll> v;
  v.push_back(q);
  v.push_back(h);
  v.push_back(s);
  sort(v.begin(),v.end());
  ll ans=0;
  if((v[0]*2)>d)
  {
    	ans=ans+(n/2)*d;
    	n=n%2;
    	if(n)
          ans=ans+v[0];
  }
  else
    ans=ans+n*v[0];
	cout<<ans<<endl;
}