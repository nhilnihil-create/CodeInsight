#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll a,b;
  cin>>a>>b;

  (a%3==0||b%3==0||(a+b)%3==0||(a==1&&b==2)||(a==2&&b==1))?cout<<"Possible"<<endl:cout<<"Impossible"<<endl;
  return 0;
}
