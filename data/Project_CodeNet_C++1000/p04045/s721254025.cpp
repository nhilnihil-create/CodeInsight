#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  vector<int> p(10);
  for(int i=0;i<K;i++){
    int a;
    cin>>a;
    p[a]++;
  }
  while(true){
    int D=N,A=0;
    while(D>0){
      A+=p[D%10];
      D/=10;
    }
    if(!A){
      break;
    }
    N++;
  }
  cout<<N<<endl;
}