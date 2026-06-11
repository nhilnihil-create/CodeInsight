#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;

#include<bits/stdc++.h>
using namespace std;

const ll INF=1e15;

template <typename X>
struct SegTree{
  using FX=function<X(X,X)>;
  int n;
  FX fx;
  const X ex;
  vector<X> dat;
  SegTree(int n_,FX fx_,X ex_) : n(),fx(fx_),ex(ex_),dat(n_*4,ex_){
    int x=1;
    while (n_>x){
      x *= 2;
    }
    n=x;
  }
  void set(int i,X x){ dat[i+n - 1]=x;}
  void build(){
    for (int k=n - 2;k>=0;k--) dat[k]=fx(dat[2*k+1],dat[2*k+2]);
  }
  void update(int i,X x){
    i += n - 1;
    dat[i]=x;
    while(i>0){
      i=(i - 1)/2;
      dat[i]=fx(dat[i*2+1],dat[i*2+2]);
    }
  }
  X get(int i){return dat[i+n-1];}
  X all(){return dat[0];}
  X query(int a,int b){ return query_sub(a,b,0,0,n);}
  X query_sub(int a,int b,int k,int l,int r){
    if(r<=a || b<=l){
      return ex;
    }else if(a<=l && r<=b){
      return dat[k];
    }else{
      X vl=query_sub(a,b,k*2+1,l,(l+r)/2);
      X vr=query_sub(a,b,k*2+2,(l+r)/2,r);
      return fx(vl,vr);
    }
  }
  int find_rightest(int a,int b,X x){ return find_rightest_sub(a,b,x,0,0,n);}
  int find_leftest(int a,int b,X x){ return find_leftest_sub(a,b,x,0,0,n);}
  int find_rightest_sub(int a,int b,X x,int k,int l,int r){
    if(dat[k]>x || r<=a || b<=l){
      return a - 1;
    }else if (k>=n - 1){
      return (k - (n - 1));
    }else{
      int vr=find_rightest_sub(a,b,x,2*k+2,(l+r)/2,r);
      if(vr!=a-1){
        return vr;
      }else{
        return find_rightest_sub(a,b,x,2*k+1,l,(l+r)/2);
      }
    }
  }
  int find_leftest_sub(int a,int b,X x,int k,int l,int r){
    if(dat[k]>x || r<=a || b<=l){
      return b;
    }else if (k>=n - 1){ 
      return (k - (n - 1));
    }else{
      int vl=find_leftest_sub(a,b,x,2*k+1,l,(l+r)/2);
      if(vl != b){
         return vl;
      }else{
         return find_leftest_sub(a,b,x,2*k+2,(l+r)/2,r);
      }
    }
  }
};

int main(){
  ll n,x;
  cin>>n>>x;
    
  using X=ll;
  auto fx=[](X x1,X x2)->X{ return min(x1,x2);};
  X ex=INF;
  SegTree<X> seg(n,fx,ex);
  
  rep(i,n){
    int y;
    cin>>y;
    seg.set(i,y);
  }
  seg.build();
  
  ll mi=INF;
  rep(i,n){
    ll sum=0;
    rep(j,n){
      if(j-i>=0) sum+=seg.query(j-i,j+1);
      else{
        int l=n+j-i;
        sum+=min(seg.query(0,j+1),seg.query(l,n-1));
      }
    }
    mi=min(mi,sum+x*i);
  }
  cout<<mi<<endl;
      
  return 0;
}