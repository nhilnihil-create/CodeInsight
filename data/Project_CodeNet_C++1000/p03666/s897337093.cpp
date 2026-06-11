#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,A,B,C,D,cnt;
  cin>>N>>A>>B>>C>>D;
  
  for(int K=1;K<=N-1;K++){
    if(A+C*K-D*(N-1-K)<=B && B<=A+D*K-C*(N-1-K)){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
