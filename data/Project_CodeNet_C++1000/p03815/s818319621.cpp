#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
  speed_up;
  ll n;
  cin>>n;
  if(n<7)
  {
      cout<<1<<endl;
      return 0;
  }
  ll a, x, ans = 2;
  x = (n - 7)/11;
  ans += x*2;
  a = 7 + x*11 + 5;
  if(n>=a)
  {
      ans++;
      cout<<ans<<endl;
      return 0;
  }
  cout<<ans<<endl;



return 0;
}

