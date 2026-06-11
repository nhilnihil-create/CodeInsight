#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt_digits(ll N)
{
  int digits=0;
  while(N>0)
  {
    N/=10;
    digits++;
  }
  return digits;
}

int main()
{
  ll N;
  cin >> N;
  int ans = cnt_digits(N);
  for(ll i=1ll; i*i<=N; ++i)
  {
    if(N%i != 0) continue;
    const ll b = N/i;
    
    int cur = max(cnt_digits(i), cnt_digits(b));
    if(ans>cur)
    {
      ans = cur;
    }
  }
  cout << ans << endl;
  return 0;
}
      
    