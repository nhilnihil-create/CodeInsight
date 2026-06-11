#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
using namespace std;
int main()
{
  speed_up;
  ll a, b, x, c, d;
  cin>>a>>b>>x;
  a = a - 1;
  if(a>=0) c = a/x + 1;
  else c = 0;

   d = b/x + 1;
   cout<<d - c<<endl;

  return 0;
}

