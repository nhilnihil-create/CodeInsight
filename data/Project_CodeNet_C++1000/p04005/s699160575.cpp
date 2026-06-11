#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll a,b,c;
  cin>>a>>b>>c;
  if(a%2==0||b%2==0||c%2==0)
  {
    cout<<0<<endl;
  }
  else
  {
    cout<<min({a*b,b*c,c*a})<<endl;
  }
}