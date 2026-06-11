#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define adrep(i,s,n) for (int i=(s);i<(n);i++)
using namespace std;
typedef long long ll;


int main(){

  ll N;

  cin>>N;
  

  vector<long long> A;
  A.resize(N);
  rep(i,N)cin>>A[i];
  
  sort( A.begin(), A.end() );
  
  ll t=0;
  ll sum=0;
  rep(i,N){

    if(i!=0){
      if(2*sum<A[i])t=i;
    }
    sum+=A[i];
    
  }
  
  cout<<N-t<<endl;

}