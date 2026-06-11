#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define adrep(i,s,n) for (int i=(s);i<(n);i++)
using namespace std;
typedef long long ll;


int main(){

  ll N;
  cin>>N;
  
  vector <ll> A;
  A.resize(3*N);
  rep(i,3*N)cin>>A[i];
  
  sort(A.rbegin(),A.rend());
  
  ll count=0;
  rep(i,N){

    count+=A[2*(i+1)-1];
    
  }
  
  cout<<count<<endl;

}
