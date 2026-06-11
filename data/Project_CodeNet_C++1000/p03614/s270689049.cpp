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

int n;
int a[100010];

int main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
    a[i]--;
  }
  ll res=0;
  rep(i,n){
    if(i<n-1&&a[i]==i&&a[i+1]==i+1){
      res++; i++;
    }else if(a[i]==i){
      res++;
    }
  }
  cout<<res<<endl;
  return 0;
}
