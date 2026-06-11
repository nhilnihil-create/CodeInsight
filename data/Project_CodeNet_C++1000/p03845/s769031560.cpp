#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
using namespace std;
int main()
{
  speed_up;
  ll n, m, sum = 0;
  cin>>n;
  ll a[n];
  for(auto &i: a)
  {
      cin>>i;
      sum +=i;
  }
  ll d = sum;
  cin>>m;
  while(m--)
  {
      ll p, x;
      sum = d;
      cin>>p>>x;
      sum = sum - a[p-1] + x;
      cout<<sum<<endl;

    }


  return 0;
}
