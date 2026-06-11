#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define RFOR(i,m,n) for(int i=m;i>=n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

int w,h;
ll p[1000000],q[1000000];
ll ans;
ll a,b;

int main(){
  cin>>w>>h;
  rep(i,w){
    cin>>p[i];
  }
  rep(i,h){
    cin>>q[i];
  }
  sort(p,p+w);
  sort(q,q+h);

  for(ll i=0;i<h+w;i++){
    if(a<w&&p[a]<q[b]||b==h){
      ans+=p[a]*(h+1-b);
      a++;
    }
    else{
      ans+=q[b]*(w+1-a);
      b++;
    }
  }

  cout<<ans<<endl;

  return 0;
}