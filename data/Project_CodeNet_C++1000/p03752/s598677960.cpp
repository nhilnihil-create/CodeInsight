#include <bits/stdc++.h>
using namespace std;
int main(){
  #define int long long
  int N,K,ans=1000000000000000;
  cin>>N>>K;
  vector<int> h(N);
  for(int i=0;i<N;i++){
    cin>>h.at(i);
  }
  for(int bit=0;bit<(1<<N);bit++){
    vector<bool> vec(N,false);
    int count=0;
    int cost=0;
    for(int i=0;i<N;i++){
      if((1<<i)&bit){
        vec.at(i)=true;
        count++;
      }
    }
    if(count!=K){
      continue;
    }
    int maxH=0;
    for(int i=0;i<N;i++){
      //cout<<i<<" "<<maxH<<" "<<h.at(i)<<endl;
      if(vec.at(i) && maxH>=h.at(i)){
        cost+=maxH-h.at(i)+1;
        maxH++;
        //cout<<i<<" "<<maxH<<" "<<maxH-h.at(i)+1<<endl;
      }
      maxH=max(maxH,h.at(i));
    }
    //cout<<cost<<endl;
    ans=min(ans,cost);
  }
  cout<<ans<<endl;
}