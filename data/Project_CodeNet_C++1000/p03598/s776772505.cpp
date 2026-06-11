#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,K;
  int S=0;
  cin>>N>>K;
  for(int i=0;i<N;i++){
   int x,n;
    cin>>x;
    if(K<=x){
     n=x-K;
    }
    else if(K-x<x){
     n=K-x;
    }
    else{
      n=x; 
    }
    S += n;
  }
  cout<<S*2<<endl;
}
