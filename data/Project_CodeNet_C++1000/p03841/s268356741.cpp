#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
//main
signed main(){
  int N;cin>>N;
  std::vector<int> v(N+1),ans(10000000,-1);
  for(int i=0;i<N;i++)cin>>v[i],v[i]--;
  typedef pair<int,int> P;
  std::vector<P> w(N);
  for(int i=0;i<N;i++)w[i]=P(v[i],i+1);
  sort(w.begin(),w.end());
  int now=0;
  for(int i=0;i<N;i++){
    int po=w[i].first,num=w[i].second;
    for(int j=1;j<num;j++){
      while(~ans[now])now++;
      ans[now]=num;if(now>=po)fin("No");
    }
    ans[po]=num;
  }
  for(int i=0;i<N;i++){
    int po=w[i].first,num=w[i].second;
    for(int j=0;j<N-num;j++){
      while(~ans[now])now++;
      ans[now]=num;if(now<=po)fin("No");
    }
  }
  bool f=false;
  cout<<"Yes"<<endl;
  for(int i=0;i<N*N;i++){
    if(f)cout<<" ";
    cout<<ans[i];f=true;
  }
  cout<<endl;
}
