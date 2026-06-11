#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
#define lint long long
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
class Hotel{
  public:
  int dist;
  int no;
  vector<int> d;
};
int mypow(int n,int x){
  int res=1;
  int cur=n;
  while(x>0){
    if(x&1)res*=cur;
    cur*=cur;
    x/=2;
  }
  return res;
}
signed main(){
  int n;cin>>n;
  vector<int> x(n);
  rep(i,n)cin>>x[i];
  x.push_back(inf);
  vector<Hotel> h(n+1);
  int l,q;cin>>l;
  cin>>q;
  rep(i,100){
    h[n].d.push_back(n);
  }
  rep(i,100){
    h[n-1].d.push_back(n);
  }
  rep(i,n-1){
    h[i].no=i;
    h[i].dist=x[i];
    auto it=lower_bound(ALL(x),x[i]+l);
    if(*it!=x[i]+l)--it;
    int ind=it-x.begin();
    h[i].d.push_back(ind);
  }
  rep1(k,100){
    rep(i,n){
      h[i].d.push_back(h[h[i].d[k-1]].d[k-1]);
    }
  }
  vector<int> res(q);
  rep(i,q){
    int a,b;cin>>a>>b;
    --a;--b;
    if(a>b){
      swap(a,b);
    }
    int buf=0;
    int cur=a;
    while(cur!=b){
      if(b<h[cur].d[0]){
        buf+=1;
        break;
      }
      auto it=lower_bound(ALL(h[cur].d),b);
      if(*it!=b)--it;
      rep(i,n){
        //printf("d[]=%lld\n",h[cur].d[i]);;
      }
      int ind=it-h[cur].d.begin();
      cur=*it;
      buf+=mypow(2,ind);
      //printf("cur = %lld, ind = %lld\n",cur,ind);
    }
    res[i]=buf;
  }
  for(const auto& val:res){
    cout<<val<<"\n";
  }
  return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
3
1
2 10
*/