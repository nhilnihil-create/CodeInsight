#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  string S; cin>>S;
  ll n=0;
  rep(i,S.size())
  {
    if(i==0)
    {
      continue;
    }
    if(S.at(i)!=S.at(i-1))
    {
      n++;
    }
  }  
  cout<<n<<endl;
  return 0;
}
