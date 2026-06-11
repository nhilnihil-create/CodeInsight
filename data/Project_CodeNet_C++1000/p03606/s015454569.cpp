#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

int gcd(int a, int b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

int lcm(int a, int b) { //最小公倍数
  return a * b / gcd(a, b);
}


int main()
{
  ll n,l[1010],r[1010];
  cin>>n;
  ll ans=0;
  rep(i,n){
    cin>>l[i]>>r[i];
    ans+=r[i]-l[i]+1;
  }
  cout<<ans<<endl;

  return 0;
}
