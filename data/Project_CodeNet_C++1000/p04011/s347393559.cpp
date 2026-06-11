#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll n,k,x,y;
  cin>>n>>k>>x>>y;
  n>=k?cout<<k*x+(n-k)*y<<endl:cout<<x*n<<endl;
  return 0;
}
