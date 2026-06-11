#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,t=0,M;
  cin>>N;
  vector<int> T(N);
  for(int &i:T){
    cin>>i;
    t+=i;
  }
  cin>>M;
  for(int i=0;i<M;i++){
    int P,X;
    cin>>P>>X;
    cout<<t+X-T[P-1]<<endl;
  }
}