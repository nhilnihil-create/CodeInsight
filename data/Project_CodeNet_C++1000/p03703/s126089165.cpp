#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct segtree{
private:
  vector<ll> node,lazy;
  ll siz;
public:
  segtree(int n){
    siz=1;
    while(siz<=n) siz*=2;
    node.resize(siz*2,0);
    lazy.resize(siz*2,0);
  }
  void eval(ll pos){
    node[pos]+=lazy[pos];
    if(pos<siz-1) {
      lazy[pos*2+1]+=(lazy[pos]/2);
      lazy[pos*2+2]+=(lazy[pos]/2);
    }
    lazy[pos]=0;
  }
  void add_q(ll a,ll b,ll x,ll l,ll r,ll pos){
    eval(pos);
    if(b<=l||r<=a) return;
    if(a<=l&&r<=b){
      lazy[pos]+=(x*(r-l));
      eval(pos);
      return;
    }
    ll mid=(l+r)/2;
    add_q(a,b,x,l,mid,pos*2+1);
    add_q(a,b,x,mid,r,pos*2+2);
    node[pos]=node[pos*2+1]+node[pos*2+2];
  }
  ll sum_q(ll a,ll b,ll l,ll r,ll pos){
    if(b<=l||r<=a) return 0;
    eval(pos);
    if(a<=l&&r<=b){
      return node[pos];
    }
    ll mid=(l+r)/2;
    return (sum_q(a,b,l,mid,pos*2+1)+sum_q(a,b,mid,r,pos*2+2));
  }
  void add(ll a,ll b,ll x){
    add_q(a,b,x,0,siz,0);
  }
  ll sum(ll a,ll b){
    return sum_q(a,b,0,siz,0);
  }
  void debug(){
    cout<<"Node:"<<endl;
    ll t=2;
    for(int i=2;i<=siz*2;i++) {
      cout<<node[i-2]<<" ";
      if(i==t){
        t*=2;
        cout<<endl;
      }
    }
    cout<<"Lazy:"<<endl;
    t=2;
    for(int i=2;i<=siz*2;i++){
      cout<<lazy[i-2]<<" ";
      if(i==t){
        t*=2;
        cout<<endl;
      }
    }
  }
};
int main(){
  ll n,k;
  cin>>n>>k;
  segtree seg=segtree(n+5);
  for(int i=0;i<=n;i++){
    seg.add(i,i+1,n-i);
  }
  priority_queue<P,vector<P>,greater<P>> pque;
  pque.push(P(0,0));
  ll ksum=0;
  for(int i=1;i<=n;i++){
    ll a;
    cin>>a;
    a-=k;
    ksum+=a;
    pque.push(P(ksum,i));
  }
  ll ans=0;
  while(!pque.empty()){
    P p=pque.top();
    pque.pop();
    ans+=seg.sum(p.second,p.second+1);
    seg.add(0,p.second,-1);
  }
  cout<<ans<<endl;
}
