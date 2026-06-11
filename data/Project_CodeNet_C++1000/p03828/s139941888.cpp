#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n;
  cin>>n;
  vector<int> prime;
  vector<bool> seen(1009,false);
  seen[0]=true;
  seen[1]=true;
  rep(i,1009) if(!seen[i]){
    prime.push_back(i);
    int k=i;
    while(k<=1000){
      seen[k]=true;
      k+=i;
    }
  }
  //for(auto p:prime) cout<<p<<endl;
   
  vector<long long> soinsu(prime.size(),0);
  for(int i=n;i>0;--i){
    rep(j,prime.size()){
      int k=i;
      while(k%prime[j]==0 && k!=0){
        soinsu[j]++;
        k/=prime[j];
        //cout<<k<<" "<<P[j]<<endl;
      }
    }
  }
  
  long long ans=1;
  rep(i,prime.size()) if(soinsu[i]>0) ans=(ans*(soinsu[i]+1))%MOD;
  cout<<ans<<endl;    
  return 0;
}