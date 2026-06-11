#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n;
  cin >> n;
  
  ll ans =  ll(n/11);
  n -= 11*ans;
  ans*=2;
  
  ll act = (ans & 1)? 5: 6;
  ll sum = 0;
  
  while(sum < n)
  {
    sum += act;
    act = (act == 5) ? 6: 5;
    ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}
