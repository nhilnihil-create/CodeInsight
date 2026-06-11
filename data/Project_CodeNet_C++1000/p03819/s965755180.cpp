#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template <typename E>
struct SegmentTree{
  using H = function<E(E,E)>;
  int n,height;
  H h;
  E ei;
  vector<E> laz;

  SegmentTree(H h,E ei):h(h),ei(ei){}

  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    laz.assign(2*n,ei);
  }

  inline void propagate(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    laz[k]=ei;
  }

  inline void thrust(int k){
    for(int i=height;i;i--) propagate(k>>i);
  }

  void update(int a,int b,E x){
    if(a>=b) return;
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
  }

  E get_val(int a){
    thrust(a+=n);
    return laz[a];
  }

  void set_val(int a,E x){
    thrust(a+=n);
    laz[a]=x;
  }
};

//INSERT ABOVE HERE
signed main(){
  auto h=[](int a,int b){return a+b;};
  SegmentTree<int> seg(h,0);

  int n,m;
  cin>>n>>m;
  vector<int> ls(n),rs(n);
  for(int i=0;i<n;i++) cin>>ls[i]>>rs[i];

  seg.init(m+1);
  vector< vector<int> > G(m+1);
  for(int i=0;i<n;i++){
    rs[i]++;
    seg.update(ls[i],rs[i],1);
    G[rs[i]-ls[i]].emplace_back(i);
  }

  int cnt=0;
  vector<int> ans;
  for(int l=m;l>0;l--){
    for(int i:G[l]){
      seg.update(ls[i],rs[i],-1);
      cnt++;
    }
    int res=cnt;
    for(int i=0;i<=m;i+=l) res+=seg.get_val(i);
    ans.emplace_back(res);
  }
  reverse(ans.begin(),ans.end());
  for(int a:ans) cout<<a<<endl;
  return 0;
}
