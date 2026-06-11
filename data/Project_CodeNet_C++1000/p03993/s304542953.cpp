#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define adrep(i,s,n) for (int i=(s);i<(n);i++)
using namespace std;
typedef long long ll;

int main(){

  ll N;
  cin>>N;
  int A[N];
  rep(i,N)cin>>A[i];
  
  int count=0;
  rep(i,N){

    //cout<<i<<" "<<A[i]-1<<" "<<A[A[i]-1]-1<<endl;
    if(A[A[i]-1]-1==i)count++;
    
  }
   
  cout<<count/2<<endl;
  
}
