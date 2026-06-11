#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> xs(n);
  for(Int i=0;i<n;i++) cin>>xs[i],xs[i]--;

  using P = pair<Int, Int>;
  priority_queue<P, vector<P>, greater<P> > pq;
  for(Int i=0;i<n;i++)
    for(Int j=0;j<i;j++)
      pq.emplace(xs[i],i);

  vector<Int> rev(n*n,-1);
  for(Int i=0;i<n;i++) rev[xs[i]]=i;

  vector<Int> cnt(n,0),ans(n*n,-1);
  for(Int i=0;i<n*n;i++){
    if(~rev[i]){
      Int k=rev[i];
      if(cnt[k]!=k) drop("No");
      ans[i]=k;
      for(Int j=k+1;j<n;j++) pq.emplace(n*n,k);
      continue;
    }
    if(pq.empty()) drop("No");
    Int k=pq.top().second;pq.pop();
    ans[i]=k;
    cnt[k]++;
  }

  cout<<"Yes"<<endl;
  for(Int i=0;i<n*n;i++){
    if(i) cout<<" ";
    cout<<ans[i]+1;
  }
  cout<<endl;
  return 0;
}
