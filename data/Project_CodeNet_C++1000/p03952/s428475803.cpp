#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000000000000000;
const long double PI=3.14159265358979;
const ll MAX=100010;

int main() {
  ll N,x;
  cin>>N>>x;
  if(N!=2&&min(x,N*2-x)<2){
    cout<<"No";
  }
  else if(N==2&&(x==1||x==3)){
    cout<<"No";
  }
  else{
    cout<<"Yes"<<endl;
    if(N==2){
      for(int i=1;i<N*2;i++){
        cout<<i<<endl;
      }
    }
    else{
      ll A[2*N];
      for(int i=1;i<N*2;i++){
        A[i]=i;
      }
      if(x==2){
        swap(A[1],A[N]);
        swap(A[x],A[N+1]);
      }
      else if(x==N*2-2){
        swap(A[N*2-1],A[N]);
        swap(A[x],A[N+1]);
      }
      else{
        swap(A[N],A[x]);
        swap(A[2],A[N-2]);
        swap(A[1],A[N+1]);
        swap(A[2*N-1],A[N-1]);
        swap(A[2*N-2],A[N+2]);
      }
      for(int i=1;i<N*2;i++){
        cout<<A[i]<<endl;
      }
    }
  }
  
    
  
}
