#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#include <math.h>
const int INF = 1001001001;
main(){
  int N;
  cin>>N;
  vector<int>S(N);
  for(int i=0;i<N;i++){
    cin>>S.at(i);
  }
  sort(S.begin(),S.end());
  int ans=0;
  for(int i=0;i<N;i++){
    ans+=S.at(i);
  }
  if(ans%10==0){
    for(int i=0;i<N;i++){
      if(S.at(i)%10!=0){ans-=S.at(i);cout<<ans<<endl;return 0;}
    }
     cout<<0<<endl;return 0;
    }
  
  cout<<ans<<endl;
  return 0;
  }