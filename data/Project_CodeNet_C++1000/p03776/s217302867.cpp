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
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
ll comb[100][100];
ll cnt(vector<ll> v,int k,double m){
    double sm=0;
    int n=v.size();
    rep(i,k)sm+=v[i];
    //if(sm!=m*k)return 0;
    ll res=0;
    int N=0;
    int K=0;
    rep(i,n){
        if(v[i]==v[k-1]){
            ++N;
        }
        if(v[i]==v[k-1]&&i<k){
            ++K;
        }
    }
    res=comb[N][K];
    return res;
}
signed main(){
  int n,a,b;cin>>n>>a>>b;
  //n=50;a=1;b=50;
  rep(i,100){
      comb[i][0]=1;
  }
  rep1(i,n){
      rep1(j,i){
          comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
      }
  }
  vector<ll> v(n);
  rep(i,n)cin>>v[i];
  double mx=0.0;
  sort(v.begin(),v.end());
  reverse(ALL(v));
  for(int i=a;i<=b;++i){
      double sm=0;
      rep(j,i){
          sm+=v[j];
      }
      sm/=(double)i;
      mx=max(mx,sm);
  }
  ll res=0;
  for(int i=a;i<=b;++i){
      if(i>a){
          if(v[0]!=v[i-1])break;
      }
      res+=cnt(v,i,mx);
  }
  printf("%.12lf\n",mx);
  cout<<res<<"\n";
  return 0;
}
