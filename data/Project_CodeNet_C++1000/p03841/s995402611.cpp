#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

ll n;
ll x[505];
ll res[505*505];
ll cnt[505];

int main(){
	cin>>n;
  rep(i,n){
    cin>>x[i];
    x[i]--;
  }

  rep(i,n*n){
    bool done=false;
    rep(j,n){
      if(x[j]==i){
        if(cnt[j]<j){
          cout<<"No"<<endl;
          return 0;
        }
        cnt[j]++;
        res[i]=j;
        done=true;
        break;
      }
    }
    if(done)continue;
    ll midx=-1;
    rep(j,n){
      if(x[j]>i&&cnt[j]<j){
        if(midx==-1||x[midx]>x[j]){
          midx=j;
        }
      }
    }
    if(midx==-1){
      rep(j,n){
        if(x[j]<i&&cnt[j]<n){
          res[i]=j;
          cnt[j]++;
          done=true;
          break;
        }
      }
      if(!done){
        cout<<"No"<<endl;
        return 0;
      }
    }else{
      res[i]=midx;
      cnt[midx]++;
    }
  }

  cout<<"Yes"<<endl;
  rep(i,n*n)cout<<res[i]+1<<" ";
  cout<<endl;
	return 0;
}
