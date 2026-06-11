#include <bits/stdc++.h>
using namespace std;



int main(){
  long long N,T;
  cin>>N>>T;
  
  vector<long long> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  long long sum=0;
  long long tmp=0;
  for(int i=0;i<N;i++){
    sum+=T-max(0LL,tmp-vec.at(i));
    tmp=vec.at(i)+T;
  }
  cout<<sum<<endl;
    
}