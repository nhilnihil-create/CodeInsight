#include <bits/stdc++.h>
#define int long long
#define rep(a,b) for(int (a)=0; (a)<(int)(b); ++(a))
#define all(a) (a).begin(),(a).end()
#define prec(a) fixed<<setprecision(a)
using namespace std;

constexpr int MOD=1000000007;
using ull=unsigned long long;
using vec=vector<ull>;
using dvec=vector<vec>;

void print(void){cout<<"\n";}

template<class HEAD,class... TAIL>
void print(HEAD&& head,TAIL&&... tail){
  cout<<head<<" ";
  print(forward<TAIL>(tail)...);
}

ull nCr(int n,int r){
  dvec c(n+1,vec(n+1,0));
  rep(i,n+1) c[i][i]=c[i][0]=1;
  for(int i=1;i<n+1;++i){
    for(int j=1;j<i;++j){
      c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
  }
  return c[n][r];
}

signed main(void){
  int N,A,B; cin>>N>>A>>B;
  vector<int> v(N);
  map<int,int> cnt;
  rep(i,N){
    cin>>v[i];
    ++cnt[v[i]];
  }
  sort(all(v)); reverse(all(v));
  double ave=0;
  map<int,int> mp;
  rep(i,A){
    ave+=v[i];
    ++mp[v[i]];
  }
  ave/=A;
  ull ans=1;
  for(auto &i : mp){
    int n,r;
    n=cnt[i.first],r=i.second;
    ull x=nCr(n,r);
    //print(n,r,":",x);
    ans*=x;
  }
  if(mp.size()==1){
    int n,r;
    n=cnt[v[0]],r=A+1;
    for(int i=r;i<=min(n,B);++i){
      ull x=nCr(n,i);
      //print(n,i,":",x);
      ans+=x;
    }
  }
  cout<<prec(10)<<ave<<endl;
  cout<<ans<<endl;
}
