#include<bits/stdc++.h>
using namespace std;
int main(){
  int Q,H,S;long long N;
  long double D;
  cin>>Q>>H>>S>>D>>N;
  vector<long double>K(4);
  K[0]=Q*4;
  K[1]=H*2;
  K[2]=S;K[3]=D/2;
  long double J=D/2;
  sort(K.begin(),K.end());
  if(K[0]==J){
    if(N%2==0){
      cout<<(long long)D*N/2<<endl;
    }
    else{
      cout<<(long long)(D*(N-1)/2+K[1])<<endl;
    }
  }
  else{
    cout<<(long long)K[0]*N<<endl;
  }
}
