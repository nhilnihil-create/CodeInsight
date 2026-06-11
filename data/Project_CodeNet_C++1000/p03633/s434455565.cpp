#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=n;i>=0;i--)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) { //最小公倍数
  return a * (b/gcd(a, b));
}



int main()
{
  ll n,t[110];
  cin>>n;
  rep(i,n)cin>>t[i];
  // rep(i,n)cout<<t[i]<<endl;
  ll ans=t[0];
  reps(i,n){
    ans=lcm(ans,t[i]);
  }
  cout<<ans<<endl;
  return 0;
}
