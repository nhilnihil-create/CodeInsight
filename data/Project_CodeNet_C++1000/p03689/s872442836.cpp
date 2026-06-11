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

ll H,W,h,w;
ll s[505];

int main(){
  cin>>H>>W>>h>>w;
  if(H%h==0&&W%w==0){
    cout<<"No"<<endl;
    return 0;
  }
  bool swapped=false;
  if(W%w==0){
    swap(H,W); 
    swap(h,w);
    swapped=true;
  }

  s[W]=1;
  for(ll i=W-w;i>=0;i-=w){
    s[i]=s[i+w]+1;
  }
  rep(i,W+1){
    if(s[i]>0)continue;
    if(i-w>=0)s[i]=s[i-w]-1;
    else s[i]=0;
  }

  cout<<"Yes"<<endl;
  if(!swapped){
    rep(i,H){
      rep(j,W)cout<<s[j+1]-s[j]<<" ";
      cout<<endl;
    }
  }else{
    rep(i,W){
      rep(j,H)cout<<s[i+1]-s[i]<<" ";
      cout<<endl;
    }
  }

  return 0;
}
