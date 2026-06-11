#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
  ll diff = a-b; if(diff<0)diff*=-1;
  for(int pc=0; pc<=n-1; pc++){
    int mc = n-1-pc;
    ll m1 = pc*c-mc*d;
    ll m2 = pc*d-mc*c;
    if(m1<=diff && diff<=m2){ cout<<"YES"<<endl; return 0; }
  }

  cout<<"NO"<<endl;

  return 0;
}
