#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  ll x,y;cin>>x>>y;
  int ans=abs(abs(x)-abs(y));
  if(x>0&&y>0&&x>y)ans+=2;
  if(x<0&&y<0&&x>y)ans+=2;
  if(x*y<0)ans+=1;
  if(x>0&&y==0||x==0&&y<0)ans+=1;
  cout<<ans<<endl;
}
