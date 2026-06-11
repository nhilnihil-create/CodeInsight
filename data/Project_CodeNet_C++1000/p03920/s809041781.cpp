#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,sum=0; cin>>N;
  vector<ll>A(N,1);
  stack<ll>S;
  for(int i=2; i<=N; i++){
    A[i-1]=A[i-2]+i;
  }
  while(sum!=N){
    if(sum<N){
      auto IT=lower_bound(A.begin(), A.end(), N-sum);
      ll z=IT-A.begin();
      sum+=A[z];
      for(int i=z+1; i>0; i--){
        S.push(i);
      }
    }
    else{
      auto IT=lower_bound(A.begin(), A.end(), sum-N);
      ll z=IT-A.begin();
      sum-=A[z];
      for(int i=z+1; i>0; i--){
        S.pop();        
      }
    }
  }
  while(!S.empty()){
    cout<<S.top()<<endl;
    S.pop();
  }
}