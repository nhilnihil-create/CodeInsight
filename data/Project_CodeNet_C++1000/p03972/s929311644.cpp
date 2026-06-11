#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,bool> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int w,h;
  cin>>w>>h;
  vector<P> cnt(w+h);
  rep(i,w){
    cin>>cnt[i].fi;
    cnt[i].se=true;
  }
  FOR(i,w,h+w){
    cin>>cnt[i].fi;
    cnt[i].se=false;
  }
  sort(begin(cnt),end(cnt));
  //rep(i,h+w) cout<<cnt[i].fi<<endl;
  int a=w+1,b=h+1;
  ll ans=0;
  ll now=0;
  rep(i,w+h){
    //cout<<cnt[i].fi<<' ';
    if(cnt[i].se){//(i,j)と(i+1,j)をつなげる
      ans+=cnt[i].fi*b;
      now+=b;
      a--;
    }else{
      ans+=cnt[i].fi*a;
      now+=a;
      b--;
    }
    //now++;
    //cout<<now<<' '<<ans<<endl;
    if(now==(h+1)*(w+1)-1) break;
  }
  cout<<ans<<endl;
}