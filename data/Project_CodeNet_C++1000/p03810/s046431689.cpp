#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

ll n;
ll a[100010];

bool dfs(){
  ll cnte=0,cnto=0,oidx=-1;
  rep(i,n){
    if(a[i]%2==0)cnte++;
    else{
      cnto++;
      oidx=i;
    }
  }
  if(cnte%2==1){
    return true;
  }else{
    if(cnto==1&&a[oidx]>1){
      a[oidx]--;
      ll g=0;
      rep(i,n)g=__gcd(g,a[i]);
      rep(i,n)a[i]/=g;
      return !dfs();
    }else{
      return false;
    }
  }
}

int main(){
  cin>>n;
  rep(i,n)cin>>a[i];
  cout<<(dfs()?"First":"Second")<<endl;
  return 0;
}
