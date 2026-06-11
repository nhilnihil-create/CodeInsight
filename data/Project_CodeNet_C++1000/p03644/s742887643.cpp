#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int div2(int i)
{
  int cnt=0;
  while(i%2==0)
  {
    i/=2;
    cnt++;
  }
  return cnt;
}

int main()
{
  int n;
  cin>>n;
  if(n==1)
  {
    cout<<1<<endl;
    return 0;
  }

  vector<int> dp(n+10,0);
  for (int i = 1; i <= n; ++i)
  {
    dp[i]=div2(i);
  }

  cout<<(max_element(dp.begin(),
   dp.end())-dp.begin())<<endl;
}