#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
long N,A,K=0;
  cin>>N;
  	for(int i=0;i<N;i++){
      cin>>K;
      A+=K;
    }
  if(A%2==0){
    cout<<"YES"<<endl;
  }
    else{
      cout<<"NO"<<endl;
    }
}