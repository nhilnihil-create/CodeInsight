#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<max(0LL,(min(b,d)-max(a,c)))<<endl;

  return 0;
}
