#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct BIT{
private:
  vector<ll> vec;
  ll siz;
public:
  BIT(ll n){
    siz=n+1;
    vec.resize(siz,0);
  }
  void upd(int pos,ll x){
    while(pos<siz){
      vec[pos]+=x;
      pos+=pos&(-pos);
    }
  }
  ll sum(ll pos){
    ll ret=0;
    while(pos>=1){
      ret+=vec[pos];
      pos-=pos&(-pos);
    }
    return ret;
  }
};
int main(){
  ll n,k;
  cin>>n>>k;
  BIT b1=BIT(n+5);
  vector<ll> vec,array;
  array.push_back(0);
  vec.push_back(0);
  ll rsum=0;
  for(int i=1;i<=n;i++){
    ll a;
    cin>>a;
    a-=k;
    rsum+=a;
    array.push_back(rsum);
    vec.push_back(rsum);
  }
  sort(vec.begin(),vec.end());
  vec.erase(unique(vec.begin(),vec.end()),vec.end());
  ll ans=0;
  for(int i=0;i<=n;i++){
    ll val=array[i];
    int idx=lower_bound(vec.begin(),vec.end(),val)-vec.begin();
    idx++;
    ans+=b1.sum(idx);
    b1.upd(idx,1);
  }
  cout<<ans<<endl;
}
