#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
  speed_up;
  ll a, b;
  cin>>a>>b;
  if(a == 1) a = 1 + 13;
  if(b == 1) b = 1 + 13;

  if(b == a) cout<<"Draw"<<endl;
  else if(a>b) cout<<"Alice"<<endl;
  else cout<<"Bob"<<endl;


return 0;
}

