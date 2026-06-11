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
  ll n,a[100010];

  cin>>n;
  rep(i,n)cin>>a[i];
  sort(a,a+n);


  ll start=0,ans=0;
  while(start<n){
    ll tmp=1;
    while(a[start]==a[start+1]&&start<n){
      tmp++;
      start++;
    }
    if(tmp%2==1)ans++;
    start++;
  }

  cout<<ans<<endl;
  return 0;
}
