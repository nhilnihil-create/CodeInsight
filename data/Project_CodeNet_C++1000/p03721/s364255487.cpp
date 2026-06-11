#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N,K;
  cin>>N>>K;
  vector<pair<long long,long long>>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i].first>>A[i].second;
  }
  sort(A.begin(),A.end());
  long long count=0;
  for(int i=0;i<N;i++){
    count+=A[i].second;
    if(count>=K){
      cout<<A[i].first<<endl;
      break;
    }
  }
}
    
