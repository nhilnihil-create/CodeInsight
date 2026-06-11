#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
  /*int N;cin>>N;
  const long mod=1000000007;
  bool prime[N+1];
  for(int i=0;i<=N;i++) prime[i]=true;
  vector<int> E;
  for(int i=2;i<=N;i++){
    if(prime[i]){
      for(int j=i*2;j<=N;j+=i) prime[j]=false;
      E.push_back(i);
    }
  }
  int L=E.size();//N以下なのでintでOK
  cout<<L<<endl;
    
 // long ans[N+1][L];
  long ans[L];
  for(int i=0;i<L;i++) ans[i]=1;
  for(int n=2;n<=N;n++){
  int F=n;//バグのもと
    for(int j=0;j<L;j++){
      while(F%E[j]==0){
        F /=X;
        ans[j]++;
      }
      if(F==1) break;
    }
  }
  long count=1;
  for(int i=0;i<L;i++){
    count *=ans[i];
    count %=mod;
  }
  cout<<count<<endl;*/
  
  
  int N;cin>>N;
  const long mod=1000000007;
  vector<bool> prime(N+1);
  for(int i=0;i<=N;i++) prime.at(i)=true;
  vector<int> E;
  for(int i=2;i<=N;i++){
    if(prime.at(i)){
      for(int j=i*2;j<=N;j+=i) prime.at(j)=false;
      E.push_back(i);
    }
  }
  int L=E.size();//N以下なのでintでOK
    
 // long ans[N+1][L];
  vector<long> ans(L,1);
  for(int n=2;n<=N;n++){
    int F=n;//これをしないと無限ループ
    for(int j=0;j<L;j++){
      int X=E.at(j);
      while(F%X==0){
        F /=X;
        ans.at(j)++;
      }
      if(F==1) break;
    }
  }
  long count=1;
  for(int i=0;i<L;i++){
    count *=ans.at(i);
    count %=mod;
  }
  cout<<count<<endl;
}
    
