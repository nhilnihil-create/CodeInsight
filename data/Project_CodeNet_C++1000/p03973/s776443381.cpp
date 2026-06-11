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
  for(Int i=0;i<n;i++) cin>>as[i];

  Int ans=0,t=1;
  for(Int a:as){
    Int num=(a-1)/t;
    ans+=num;
    if(t==1) a=1;
    else if(num) a=t-1;
    chmax(t,a+1);
  }
  cout<<ans<<endl;
  return 0;
}
