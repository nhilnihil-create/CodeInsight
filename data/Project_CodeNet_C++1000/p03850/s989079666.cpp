#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;

  vector<Int> as(n);
  vector<Int> cs(n,1);
  for(Int i=0;i<n;i++){
    if(i){
      char c;
      cin>>c;
      if(c=='+') cs[i]=+1;
      if(c=='-') cs[i]=-1;
    }
    cin>>as[i];
  }
  const Int INF = 1e15;
  vector<Int> dp0(n+1,-INF);
  vector<Int> dp1(n+1,-INF);
  vector<Int> dp2(n+1,-INF);
  dp0[0]=0;

  for(Int i=0;i<n;i++){
    if(cs[i]>0){
      // stay
      chmax(dp0[i+1],dp0[i]+as[i]);
      chmax(dp1[i+1],dp1[i]-as[i]);
      chmax(dp2[i+1],dp2[i]+as[i]);

      // close
      chmax(dp0[i+1],dp1[i]-as[i]);
    }
    if(cs[i]<0){
      // open + stay
      chmax(dp1[i+1],dp0[i]-as[i]);
      chmax(dp2[i+1],dp1[i]+as[i]);
      chmax(dp2[i+1],dp2[i]+as[i]);

      // open + close
      chmax(dp0[i+1],dp0[i]-as[i]);
      chmax(dp1[i+1],dp1[i]+as[i]);
      chmax(dp2[i+1],dp2[i]+as[i]);
    }
  }
  cout<<max({dp0[n],dp1[n],dp2[n]})<<endl;
  return 0;
}
